#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
long long c,t,n,k,a,b;
vector<int> g[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //cout<<"hello"<<endl;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<n;j++){
                int x,y;
                cin>>x>>y;
            //cin>>a>>b;
            //g[a].push_back(b);
            //g[b].push_back(a);
        }
        if(k%2==0){
            cout<<k/2<<endl;
        }else{
        cout<<k-k%2<<endl;
        }
        /*
        for(int ii=1;ii<=n;ii++){
            for(int jj=0;jj<g[ii].size();jj++){
                cout<<g[ii][jj]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        */
    }
    return 0;
}


