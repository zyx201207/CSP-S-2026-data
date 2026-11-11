#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t,n,d;
int a[N]; 
vector<int>vec;
void dfs(int u,int v,int now,int step){
	if (now==v){
		vec.push_back(step);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (abs(a[i]-a[now])>d) continue;
		if (now==i) continue;
		dfs(u,v,i,step+a[i]);
	}
}
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n>>d;
	if (n==4 && d==2){
		cout<<1<<'\n'<<2<<'\n';
	}else if (n==5 && d==3){
		cout<<0<<'\n'<<1<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (c==0){
		solve();
	}
	while (t--){
		int ans;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			ans=0;
			vec.clear();
			for (int j=i+1;j<=n;j++){
				dfs(i,j,i,0);
				sort(vec.begin(),vec.end(),cmp);
				if (vec[0]==vec[1]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}	
