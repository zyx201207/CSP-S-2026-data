#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx;
vector<int> s(0);
void dfs(int nn,int last){
	if(nn==m){
		int tmp=s[0];
		for(int i=1;i<m;i++){
			tmp=(tmp&s[i]);
		}
		mx=max(mx,tmp);
		return;
	}
	for(int i=last+1;i<=n;i++){
		s.push_back(a[i]);
		dfs(nn+1,i);
		s.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){
		int maxx=a[1];
		for(int i=2;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<mx;
	return 0;
} 
