#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n;
long long d,x[N];
struct node{
    int u,dd;
};
int tp[N][101];
queue<node>q;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            long long dd=x[2]-x[1];
            int k=d/dd;
            //cout<<n<<" "<<d<<" "<<k<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
            if(k<=1){
                cout<<0<<endl;
            }
            if(k>=2){
                if(n>=2*k-1)cout<<n-2*k+1<<endl;
                else cout<<0<<endl;
            }
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            int ans=0;
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]>x[n]-x[i]){
                    int l=1,r=i-1;
                    while(r-l>1){
                        int mid=(l+r)/2;
                        if(x[i]-x[mid]>d){
                            l=mid;
                        }
                        else{
                            r=mid-1;
                        }
                    }
                    if(x[i]-x[r]>d){
                        l=r;
                    }
                    if(l!=i-1)ans+=l;
                    else ans+=l-1;
                }
                else if(x[i]-x[1]<x[n]-x[i]){
                    int l=i+1,r=n;
                    while(l<r){
                        int mid=(l+r)/2;
                        if(x[mid]-x[i]>d){
                            r=mid;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                    if(l!=i+1)ans+=n-l+1;
                    else ans+=n-l;
                }
            }
            cout<<ans/2<<endl;
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            memset(tp,0,sizeof tp);
            q.push((node){i,0});
            while(!q.empty()){
                node no=q.front();
                q.pop();
                tp[no.u][no.dd]++;
                for(int j=no.u+1;j<=n;j++){
                    if(x[j]-x[no.u]<=d){
                        q.push((node){j,no.dd+1});
                    }
                }
            }
            for(int j=i+1;j<=n;j++){
                for(int k=1;k<=100;k++){
                    if(tp[j][k]==2){
                        ans++;
                        //cout<<i<<" "<<j<<endl;
                    }
                    if(tp[j][k]!=0){
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
