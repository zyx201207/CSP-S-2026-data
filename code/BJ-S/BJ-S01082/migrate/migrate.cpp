#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int c,t;
int n,d,x[N];
long f[2005][2005][2];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
                memset(f,0,sizeof(f));
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            for(int i=1;i<=n;i++){
                f[i][i][0]=0;
                f[i][i][1]=1;
            }
            for(int j=n-1;j>=1;j--){

                int l=upper_bound(x+1,x+n+1,x[j]+d)-x;
                l--;
                if(x[n]-x[j]<=d){
                    l=n;
                }

                for(l;l>j;l--){
                        //cout<<l<<"%\n";
                        for(int i=l;i<=n;i++){
                            if(!(f[l][i][0]>=f[j][i][0]&&f[j][i][0]!=0)){

                            f[j][i][0]=f[l][i][0]+1;
                            f[j][i][1]+=f[l][i][1];}
                            //cout<<f[j][i][1]<<endl;
                        }
                }
                ed:;

            }
            int sum=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                        //cout<<f[i][j][0]<<' '<<f[i][j][1]<<' '<<i<<' '<<j<<endl;
                    if(f[i][j][1]==2){
                        sum++;
                    }
                }
            }
            cout<<sum<<endl;
        }
    }
    else if(11<=c&&c<=12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            int ca=x[2]-x[1];
            int k=d/ca;
            if(k<=1){
                cout<<0<<endl;

            }
            else{
            int sum=max(n-(2*k-1),0ll);
            cout<<sum<<endl;
            }
        }
    }
    return 0;
}
