#include<bits/stdc++.h>
using namespace std;
int ans[300050],n,m,a[500050],v[300050];
stack<int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				while(b.size()&&b.top()!=a[j]){
					b.pop();
				}
				if(b.size()) b.pop();
			}
			b.push(a[j]);
			v[a[j]]=1;
		}
		while(b.size()){
			ans[b.top()]++;
			cout<<b.top()<<' ';
			b.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
} 
