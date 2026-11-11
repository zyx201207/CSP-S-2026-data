#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int p[N];
bool v[N];
int ans=0;
void dfs(int cnt,int x){
	if(cnt==m){
		/*for(int i=1;i<=n;i++){
			cout<<v[i]<<' ';
		}*/
		//cout<<'\n';
		for(int i=2;i<=m;i++){
			p[i]&=p[i-1];
		}
		ans=max(p[m],ans);
		return ;
	}
	for(int i=x;i<=n;i++){
		if(v[i]==1){
			continue;
		}else{
			v[i]=1;
			p[cnt+1]=a[i];
			dfs(cnt+1,i+1);
			v[i]=0;
			p[cnt+1]=0;
			
		}
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ma=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	dfs(0,1);
	cout<<ans;
	return 0;
} /*
5 3
31 3 1 15 7
*/
//按位与是& 
