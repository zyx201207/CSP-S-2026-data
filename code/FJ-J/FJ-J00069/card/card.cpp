#include<bits/stdc++.h>
using namespace std;
int points[300005];
int a[500005];
int ans[300005];
stack<int> stk;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(points,0,sizeof(points));
		for(int j=i;j<=n;j++){
			if(points[a[j]]==0){
				stk.push(a[j]);
				points[a[j]]++;
			}else{
				int i=stk.size();
				int x=stk.top();
				while(x!=a[j]){
					points[x]--;
					stk.pop();
					x=stk.top();
					i--;
				}
			}	
		}
		for(int i=1;i<=m;i++){
			if(points[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
