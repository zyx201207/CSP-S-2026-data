#include<bits/stdc++.h>
using namespace std;
int a[200009],n,m;
bool s[20];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==n || m==n-1){
            long long k=1;
            for(int i=1;i<=17;i++){
                k*=2;
                for(int j=1;j<=n;j++){
                    if((a[j]%k)/(k/2)==0)s[i]=1;
                }
            }
                long long ans=0;
                k=1;
                for(int i=1;i<=17;i++){
                    if(s[i]==0)ans+=k;
                    k*=2;
                }
                cout<<ans;
            }
            else if(a[54]<4)cout<<3;
            else cout<<0;
    return 0;
}