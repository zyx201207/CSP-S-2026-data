#include<bits/stdc++.h>
using namespace std;
int n,m,a[500020],b[500020],dx[500020];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<int> c;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				c.push(a[j]);
				b[a[j]]=1;
			}
			else{
				while(c.top()!=a[j]){
					int k=c.top();
					b[k]=abs(b[k]-1);
					c.pop();
				}
			}
		}
		while(!c.empty()){
			int k=c.top();
			dx[k]++;
			c.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<dx[i]<<' ';
	return 0;
}
