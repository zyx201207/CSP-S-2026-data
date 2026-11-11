#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1,sum;
long long a[200005];
string c[200005],s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x>>s;
        if(s==c[cnt]){
            a[cnt]+=x;
        }else{
            cnt++;
            a[cnt]=x;
            c[cnt]=s;
        }
    }
    long long l=1;
    long long r=cnt;
    while(l<r){
        if(c[l]!=c[r]){
            sum+=min(a[l],a[r]);
        }
        if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }else if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }else if(a[l]==a[r]){
            l++;
            r--;
        }
    }
    cout<<sum;
    return 0;
}
