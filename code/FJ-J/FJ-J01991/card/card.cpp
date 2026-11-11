#include<bits/stdc++.h>
using namespace std;
const int M=2*1e5+5;
stack<int>c;
map<int,int>l;
int n,m,a[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=a[i-1])p=false;
	}
	if(p==true){
		for(int i=1;i<=m;i++){
			cout<<i<<' ';
		}
	}
	for(int i=1;i<=n;i++){
	map<int,int>g;
		for(int j=i;j<=n;j++){
			if(g[a[j]]==0){
				c.push(a[j]);
				g[a[j]]++;
			}
			else {
				while(!c.empty()&&c.top()!=a[j]){
					int x=c.top();c.pop();
					g[x]--;
				}
			}
		}
		while(!c.empty()){
			int x=c.top();c.pop();
			l[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<l[i]<<" ";
	}
	return 0;
}
