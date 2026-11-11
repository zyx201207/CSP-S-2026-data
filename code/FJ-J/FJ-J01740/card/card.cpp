#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans[3*N],a[5*N];
bool v[5*N];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=1;
				q.push(a[j]);
			}else{
				while(q.top()!=a[j]){
					v[a[j]]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
