#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300003];
bool v[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(v[a[j]]==1){
				while(q.top()!=a[j]){
					v[q.top()]=0;
					q.pop();
				}
			}else{
				q.push(a[j]);
				v[a[j]]=1;
			}
		}memset(v,false,300003);
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
	return 0;
}
//60AC
