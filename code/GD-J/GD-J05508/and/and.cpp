#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7,L=30;
int n,m,a[N],ans,c[100];
vector<int> v,g;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;for(int i=1,x;i<=n;i++) cin>>x,v.push_back(x);
	while(true){
		memset(c,0,sizeof c);int id=-1;bool flag=false;
		for(auto u:v) for(int j=0;j<=L;j++) if(u&(1<<j)) c[j]++;
		for(int i=0;i<=L;i++) if(c[i]>=m) flag=true,id=i;
		if(!flag) break;ans+=(1<<id);
		for(auto u:v) if(u&(1<<id)) g.push_back(u-(1<<id));
		v.clear();for(auto u:g) v.push_back(u);g.clear();
	}
	cout<<ans<<'\n';
	return 0;
}
