#include<bits/stdc++.h>
#define int long long
//voidÄ©Î²Òª¼Óreturn;
using namespace std;
int n,m;
const int N=2e5+10; 
int a[N];
vector<int>g;
int mmax=0;
void dfs(int step){
	if(step>n){
		if((int)g.size()==m){
			int s=g[0];
			for(int i=1;i<(int)g.size();i++)s=s&g[i];
			mmax=max(mmax,s);
		}
		return;
	}
	g.push_back(a[step]);
	dfs(step+1);
	g.pop_back();
	dfs(step+1);
	return;
}
int l[N],r[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		} 
		cout<<ans;
		return 0;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(m==n-1){
		l[1]=a[1];
		r[n]=a[n];
		for(int i=2;i<=n-1;i++){
			l[i]=l[i-1]&a[i];
			r[i]=r[i+1]&a[i];
		}
		int maxn=0; 
		for(int i=1;i<=n;i++){
			maxn=max(maxn,l[i-1]&r[i+1]);
		}
		cout<<maxn;
		return 0;
	}	
	else dfs(1);
	cout<<mmax;
	return 0;
}
//60
