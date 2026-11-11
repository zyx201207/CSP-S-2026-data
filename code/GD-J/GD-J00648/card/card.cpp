#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int T=1;T<=n;T++){
		memset(v,0,sizeof(v));
		stack <int> q;
		for(int i=T;i<=n;i++){
			if(v[a[i]]){
				while(q.top()!=a[i]){
					v[q.top()]=0;
					q.pop();
				}
				v[a[i]]=1;
			}
			else q.push(a[i]),v[a[i]]=1;
		}
		while(!q.empty()) cnt[q.top()]++,q.pop();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

