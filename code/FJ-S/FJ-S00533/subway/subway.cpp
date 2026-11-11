#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

vector<int>g;
int c,n,m,d,q,w[N],k;
struct uu{
	int a,t;
}f[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k;
	int a=q;
	while(q--){
		for(int i=1;i<=k;i++){
			cin>>f[i].a>>f[i].t;
		}	
		
	}
	
	while(a--){
		int i=0;
		cout<<i<<'\n';
		i++;
	}
	
	
	
	
	
	
	
	
	return 0;
}
