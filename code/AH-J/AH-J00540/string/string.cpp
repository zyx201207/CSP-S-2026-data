#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char ch[200005];
int main(void){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    long long l=1,r=n;
    while(l<r){
        if(ch[l]==ch[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                l++;
                r--;
            }
        }
        else{
            ans+=min(a[l],a[r]);
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}
