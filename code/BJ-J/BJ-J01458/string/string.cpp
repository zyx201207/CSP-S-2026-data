#include<bits/stdc++.h>
using namespace std;
long long n,l,r,a[200005],len,ans[1000];
char s[200005];
bool f=true;
void add(long long x){
    long long cnt=0;
    while(x!=0){
        ++cnt;
        ans[cnt]+=x%10;
        x/=10;
    }
    if(f){
        len=cnt;
        f=false;
    }
    long long c;
    for(int i=1;i<=len;i++){
        if(ans[i]>=10){
            if(i+1>len)
                ++len;
            c=ans[i]/10;
            ans[i]=ans[i]%10;
            ans[i+1]+=c;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    l=1;
    r=n;
    while(l<r)
    {
        if(a[l]<a[r]){
            if(s[l]!=s[r]){
                add(a[l]);
            }
            a[r]-=a[l];
            ++l;
        }
        else if(a[l]>a[r]){
            if(s[l]!=s[r]){
                add(a[r]);
            }
            a[l]-=a[r];
            --r;
        }
        else if(a[l]==a[r]){
            if(s[l]!=s[r]){
                add(a[l]);
            }
            ++l;
            --r;
        }
    }
    for(int i=len;i>=1;i--)
        cout<<ans[i];
    return 0;
}
