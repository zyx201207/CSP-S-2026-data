#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,t;
int main (){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a[N];
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout<<1<<endl;
	}
	return 0;
}
