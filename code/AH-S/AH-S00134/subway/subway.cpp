#include <bits/stdc++.h>
using namespace std;
const long long N=5e3+5;
long long c,n,m,d,q,w[N],dis[N][N];
struct Node{
	long long a,t;
};
vector<Node> k[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(long long i=1;i<=n;i++) cin>>w[i];
	for(long long i=1;i<=m;i++){
        long long x;
        cin>>x;
        for(long long j=1;j<=x;j++){
			long long a,t;
			cin>>a>>t;
            k[i].push_back(Node{a,t});
            k[a].push_back(Node{i,t});
        }
	}
	while(q--){
        
	}
	return 0;
}
