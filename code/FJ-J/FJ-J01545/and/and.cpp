#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005],p=0,ans=0;
bool v[200005];
void dfs(int ls){
	if(ls==m+1) {
		ans=a[1];
		for(int i=1;i<=m;i++){
			//cout<<a[i]<<' ';
			ans&=a[i];
		}
		//cout<<'\n';
		p=max(ans,p);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
		a[ls]=b[i];
		v[i]=1;
		dfs(ls+1);
		v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	dfs(1);
	cout<<p;
	return 0;
}
