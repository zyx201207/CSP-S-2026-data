#include<bits/stdc++.h>
using namespace std;
const long long INF=2e9+100;
const int N=300+10;
int c,t;
int n;
long long d;
long long x[N];
int ds[N][N];
int a[N][N];
int fl[N];
int fo[N],foo[N];
long long ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long dx=x[2]-x[1];
        if(d<=dx){
            cout<<0<<endl;
            continue;
        }
        long long y=d/dx;
        cout<<max((long long)0,n-(y*2-1))<<endl;


    }
    return 0;

    }
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                ds[i][j]=0;
                a[i][j]=0;
            }
            fl[i]=-1;
            fo[i]=foo[i]=1;
        }
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int l=i,s=1;
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[l]>d){
                    if(x[l]-x[j-1]>d){
                        break;
                    }
                    l=j-1;
                    if(x[j]-x[l]>d){
                        break;
                    }
                    s++;
                }
                if(s==1) fl[i]=j;
                ds[i][j]=s;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //cout<<ds[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                if(ds[i][j]!=2) continue;
                int p=0;
                for(int k=i+1;k<j;k++){
                    if(ds[i][j]*ds[i][k]*ds[k][j]!=0){
                       if(ds[i][j]==ds[i][k]+ds[k][j]) {
                            p++;
                       }
                    }
                }
                a[i][j]=p;
                if(p==2){
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //cout<<a[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int i=1;i<=n;i++){
            //cout<<fl[i]<<"  ";
        }
        //cout<<endl;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                vector <int> ve;
                ve.clear();
                ve.push_back(i);
                int fg=0;
                for(int k=i;k<j;){
                    if(fl[k]==-1){
                        fg=1;
                        break;
                    }
                    if(fl[k]>=j){
                        break;
                    }
                    k=fl[k];
                    ve.push_back(k);

                }
                ve.push_back(j);
                for(int k=0;k<ve.size()-2;k++){
                    if(a[ve[k]][ve[k+2]]!=1) fg=1;
                }
                if(fg==0){
                    fo[i]++;
                    foo[j]++;
                }
            }

        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i][j]==2){
                    ans+=foo[i]*fo[j];
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
