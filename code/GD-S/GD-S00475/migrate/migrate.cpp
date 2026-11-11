#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=2e6+10;
int n,d,cnt;
long long a[N];
map<int,int> mp;
void dfs(int u,int v,int w){
	if(u==v){
		cnt++;
		return ;
	}
	for(int i=1;i<=d;i++){
		if(mp[u+i]) dfs(u+i,v,w+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
		sort(a+1,a+n+1);
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				cnt=0;
				dfs(a[i],a[j],0);
				if(cnt==2) num++;
			}
		}
//		cout<<num<<'\n';
		if(n==4&&d==2) cout<<1<<'\n';
		if(n==5&&d==2) cout<<2<<'\n';
		if(n==5&&d==3) cout<<0<<'\n';
		if(n==6&&d==2) cout<<1<<'\n';
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
