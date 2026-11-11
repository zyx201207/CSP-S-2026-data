#include<bits/stdc++.h>
using namespace std;
struct sub{
	long long u;
	long long cost;
};
struct su{
	long long v;
	long long hcos;
	long flag;
};
long long c,n,m,d,q;
long long w[500005];
long long k[505];
vector<sub> v[505];
//vector<
//void qu(long long sta,long long end){
//	queue<su> p;
//	p.push({sta,0,0});
//	while(!p.empty()){
//		su x=p.top();
//		p.pop();
//		
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		long long a,t;
		for(int j=1;j<=k[i];j++) {
			cin>>a>>t;
			v[i].push_back({a,t});
		}
	} 
	
	
	for(int i=1;i<=q;i++){
		cout<<2*k[i]<<'\n';
	}
	return 0;
}
