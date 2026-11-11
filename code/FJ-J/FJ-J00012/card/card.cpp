#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int g[300005];
int d[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[j]=0;
		}
		while(!q.empty()) q.pop();
 		for(int j=i;j<=n;j++){
			if(d[a[j]]){
				while(!q.empty()){
					if(q.top()==a[j]) break;
					d[q.top()]--;
					q.pop();
				}
			}
			else q.push(a[j]),d[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			if(d[j]) g[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<" ";
	}
	return 0;
}
