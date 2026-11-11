#include<bits/stdc++.h>
using namespace std;
bool in_stack[330000],vis[330000];
int ans[330000],a[550000],f[330000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool flag=0;
	cin>>n>>m;
	stack<int> s;
	for(int i=0;i<n;i++){
		cin>>a[n-i];
		if(a[n-i]<=a[n-i+1]){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i>=n;i++){
			ans[a[i]]=max(ans[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[a[i]]){
				while(s.top()!=a[i]&&f[s.top()]>f[a[i]]){
					ans[s.top()]=i-f[s.top()];
					in_stack[s.top()]=1;
					s.pop();
				}
				if(in_stack[a[i]]){
					ans[a[i]]++;
				}
			}else{
				vis[a[i]]=1;in_stack[a[i]]=0;
				s.push(a[i]);
				f[a[i]]=i;
			}
		}
		while(!s.empty()){
			ans[s.top()]=n-f[s.top()]+1;
			s.pop();
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
} 
