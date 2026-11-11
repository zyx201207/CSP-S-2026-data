#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m,flag1=1,flag2=1,l=0,r=0;
int a[500005],f[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                if(f[j]-f[i]-(a[j]-a[i])*(i-1)<=m){
                        ans=j-i+1;
                        l=i,r=j;
                        break;
                    }
            }
            if(l)break;
        }
        for(;r<=n;){
            r++;
            if(f[r]-f[l]-(a[r]-a[l])*(l-1)<=m)if(r-l>ans)ans=r-l;
            if(f[r]-f[l]-(a[r]-a[l])*(l-1)>m)l++;
        }
        cout<<ans;
        return 0;
 }
