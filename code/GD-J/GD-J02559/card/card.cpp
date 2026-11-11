#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],u[500005],ans[500005];
queue<int> q; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		u[500005]={0};
		for(int j=i;j++;j<=n){
			if(u[a[j]]==1){
				while(!q.empty()){
					q.pop();
				}
				u[a[j]]=0;
			}
			q.push(a[j]);
			u[a[j]]++;
		}
		while(!q.empty()){
			int t=q.front();
			ans[t]++;
			q.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
