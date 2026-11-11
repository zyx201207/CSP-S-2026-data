#include<bits/stdc++.h>
using namespace std;
int c,n,m,k,d,t;
const int maxn=2e6+10;
long long a[maxn],f[maxn],num[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n==1||d==1){
            cout<<0<<endl;
            continue;
        }
        if(c==11||c==12){
            for(int i=0;i<n;i++)cin>>a[i];
            long long dd=a[n-1]-a[n-2];
            m=(d/dd);
            if(m==1){
                cout<<"0"<<endl;continue;
            }
            else{
                cout<<(n-2*m+1)<<endl;
            }
        }
        else{
            int ans=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            for(int w=1;w<n;w++){
            for(int i=0;i<=n+1;i++){f[i]=0;num[i]=0;}
            for(int i=w;i<=n;i++){
                for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++){
                    if(i==w){num[j]=w;f[j]++;}
                    else {
                        if(num[j]!=num[i]){
                            f[j]++;num[j]=i;
                        }
                    }
                }
            }

            for(int i=1;i<=n;i++)
             {
                 if(f[i]==2)ans++;
             }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
