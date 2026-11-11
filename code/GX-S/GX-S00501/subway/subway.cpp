#include<iostream>
#include<vector>
using namespace std;
const int N=5e5+7;
const int M=1e9+7;
//struct node{    it seems like it is not a tu
//    int u;
//    int w;
//};
//vector<node> a[N];
bool b[N]={};
bool b1[N]={};
int c,n,m,d,q;
int val1[N]={};   // kou to ting
int val2[N]={};   //line 1
int cd[N]={};     //line 2
int sval;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    cin>>val1[i];
    }

    if(c==20||c==21){  //judge if the start point and the end point are on the same subway line
    for(int i=1;i<=n;i++){
    int k;
    cin>>k;
            int frontj=0;
            for(int j=1;j<=2*k;j++){
                int t;
                cin>>t;
                if(j%2==1){
                    if(i==1) b[t]=1;
                     else b1[t]=1;
                     frontj=t;
                }else{
                   if(i==1) val2[frontj]=t;
                   else cd[frontj]=t;
                }
            }
        }

            for(int i=1;i<=q;i++){
                int x,y;
                cin>>x>>y;
                if(b[x]==b[y]&&b1[x]!=b1[y]){

                long long ans=val1[x]+val1[y]+val2[x]+val2[y];
                cout<<ans<<endl;
                }else if(b[x]!=b[y]&&b1[x]==b1[y]){
                    long long ans=val1[x]+val1[y]+cd[x]+cd[y];
                    cout<<ans<<endl;
                    }else if(b[x]==b[y]&&b1[x]==b1[y]){
                    long long ans=min(val1[x]+val1[y]+val2[x]+val2[y],val1[x]+val1[y]+cd[x]+cd[y]);
                    cout<<ans<<endl;
                    }else{

                        int mn=M;
                    long long ans=val1[x]+val1[y];
                    for(int j=1;j<=m;j++){
                        if(b[j]==true&&b1[j]==true&&val2[j]+cd[j]<mn){
                            mn=val2[j]+cd[j];
                        }
                    }
                ans+=mn;
                if(b[x]==true) ans+=val2[x];
                else ans+=cd[x];
                if(b[y]==true) ans+=val2[y];
                else ans+=cd[y];
                cout<<ans<<endl;

            }
        }
    }
    return 0;
}
