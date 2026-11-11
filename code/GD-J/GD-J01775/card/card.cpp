#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],b[N],c[N];
stack<int>sss;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)c[j]=0;
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			int x=c[a[j]];
			if(x==2){
				while(sss.top()!=a[j]&&!sss.empty())sss.pop();
				c[a[j]]=1;
			}
			else sss.push(a[j]);
		}
		while(!sss.empty()){
			b[sss.top()]++;
			sss.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
