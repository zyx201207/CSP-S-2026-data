#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[200003];
struct Node{
	int val,deg;
	bool operator < (const Node &o) const{
		if(deg!=o.deg) return deg>o.deg;
		else return val>o.val;
	}
};
int n,m;
Node b[200003];
int c[200003];
int A;
bool vis[200003];
void dfs(int cur){
	if(cur==m+1){
		int lin=c[1];
		for(int i=2;i<=m;i++){
			lin&=c[i];
		}
		A=max(A,lin);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		c[cur]=a[i];
		vis[i]=true;
		dfs(cur+1);
		vis[i]=false;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			b[i].val=a[i];
			int sum=0;
			int cnt=0;
			while(a[i]){
				if(a[i]%2==0) sum++;
				a[i]/=2;
				cnt++;
			}
			b[i].deg=cnt;
		}
		sort(b+1,b+n+1);
		int ans=b[1].val;
		for(int i=2;i<=m;i++){
			ans&=b[i].val;
		} 
		cout<<ans<<' ';		
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<A;
		return 0;
	}
	cout<<0; 
	return 0;
} 
//4 2
//3 15 12 12

