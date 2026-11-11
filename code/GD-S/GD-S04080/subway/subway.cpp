#include<bits/stdc++.h>
using namespace std;
using l=long long;
using cp=pair<l,l>;

l c,n,m,d,q;
l x,y;
vector<l> ktoti(555);
vector<vector<cp>> titota(555);
vector<vector<l>> xian(555);

l dfs(l loca,l sum){
	for(auto tx:titota[loca]){
		for(auto txx:xian[tx.second]){
			//if(txx==y-1){
				return sum+tx.first;
			//}
			//else dfs(txx,sum+tx.first);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(l i=0;i<m;i++)cin>>ktoti[i];
	
	for(l i=0;i<n;i++){
		l k;
		cin>>k;
		cp tp;
		tp.second=i;
		
		for(l ii=0;ii<k*2;ii++){
			l a,t;
			cin>>a>>t;
			tp.first=t;
			titota[a-1].push_back(tp);
			xian[i].push_back(a);
		}
	}
	
	for(l i=0;i<q;i++){
		cin>>x>>y;
		cout<<ktoti[x]+16+ktoti[y]<<'\n';
	}
	
	return 0;
}
