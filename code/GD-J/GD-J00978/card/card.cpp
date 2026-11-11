#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
stack<int> s;
int ans[M],last[M];
int laf[M];
bool vis[M],spa=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) spa=0;
	}
	if(spa){
		for(int i=1;i<=n;i++){
			laf[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<laf[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			last[i]=0;
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
				s.pop();
			}
			vis[a[j]]=1;
			s.push(a[j]);
		}
		while(!s.empty()){
			last[s.top()]=1;
			s.pop();
		}
		for(int i=1;i<=m;i++) ans[i]+=last[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
