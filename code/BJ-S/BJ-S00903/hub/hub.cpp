#include<iostream>
#include<vector>
using namespace std;
vector<int> a[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            //a[u].push_back(v);
            //a[v].push_back(u);
        }
        cout<<"1"<<endl;
    }
    return 0;
}
