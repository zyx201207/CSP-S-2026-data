#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[500005];
int vis[500005];
int ans[500005];
stack<int> s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f1=false;
		}
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(vis[a[j]]>0){
					while(!s.empty() and s.top()!=a[j]){
						vis[s.top()]--;
						s.pop();
					}
					s.pop();
					vis[a[j]]=1;
					s.push(a[j]);
				}else{
					s.push(a[j]);
					vis[a[j]]++;
				}
			}
			while(!s.empty()){
				ans[s.top()]++;
				s.pop();
			}
			for(int i=1;i<=m;i++){
				vis[i]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		for(int i=n;i>=1;i--){
			if(vis[a[i]]==0){
				vis[a[i]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ans[a[j]]++;
				if(vis[a[j]]!=0){
					j=vis[a[j]];
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
/*

*/
