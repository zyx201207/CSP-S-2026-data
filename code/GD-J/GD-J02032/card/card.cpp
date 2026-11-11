#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
			if(a[n]!=a[i]) ans[a[n]]++;
		}
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<" ";
		return 0;
	}
	stack<int> q;
	for(int i=1;i<=n;i++){
		memset(f,false,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]) {
				while(!q.empty()) {
					if(q.top()!=a[j]){
						f[q.top()]=0;
						q.pop();
					}
					else
						break;
				}
				continue;
			}
			q.push(a[j]);
			f[a[j]]=true;
			
		}
		
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
