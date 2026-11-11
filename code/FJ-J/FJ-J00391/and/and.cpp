#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,string>
const int MAXN=2005;
int n,m,a[MAXN],ans=0;
bool choose[MAXN];
void check(){
	int res=2097151;
	for(int i=1;i<=n;i++){
		if(choose[i]){
			res&=a[i];
		}
	}
	ans=max(ans,res);
} 
void dfs(int p,int step){
	if(p>n){
		if(step==m)check();
		return;
	}
	if(step>m) return;
	if(n-p+1<step-m) return;
	choose[p]=1;
	dfs(p+1,step+1);
	choose[p]=0;
	dfs(p+1,step);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	if(n>2005){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0);
	}else if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]); 
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
