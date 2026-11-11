#include<bits/stdc++.h>
using namespace std;
vector<long long> e[33];
long long a[33];
bool f[200005];
int n,m,ans,maxn=INT_MIN,an=INT_MIN;
void dfs(int p,int s){
	if(p==m+1){
		an=max(an,s);
//		cout<<an<<endl;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			dfs(p+1,s&a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		maxn=max(x,maxn);
		if(i==1) ans=x;
		else ans=ans&x;
	} 
	if(m==1) cout<<maxn;
	else if(m==n) cout<<ans;
	else{
		dfs(1,4095);
		cout<<an;
	}
	return 0;
}
