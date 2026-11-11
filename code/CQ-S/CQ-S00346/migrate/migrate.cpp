#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,dis,n,cnt;
long long d,a[N];
vector<int> e[N];
void dfs(int st,int ed,int x,int dist){
	if(dist>dis) return;
	if(x==ed){
		if(dist<dis){
			dis=dist;
			cnt=1;
		}
		else if(dist==dis) cnt++;
		return;
	}
	for(int y:e[x]){
		if(y>ed) continue;
		dfs(st,ed,y,dist+1);
	}
}
void task1(){
	for(int i=1;i<=n;i++){
		e[i].clear();
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d) break;
			e[i].push_back(j);
		}
		reverse(e[i].begin(),e[i].end());
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis=0x3f3f3f3f;
			cnt=0;
			dfs(i,j,i,0);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
//	freopen("migrate33.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1){cout<<"0\n";continue;}
		if(n<=9){task1();continue;}
		long long di=a[2]-a[1];
		long long cc=min(n-1ll,d/di);
		if(cc==0 || cc==1){cout<<"0\n";continue;}
		int ru=cc+cc;
		cout<<max(n-ru+1,0)<<'\n';
	}
	return 0;
}

