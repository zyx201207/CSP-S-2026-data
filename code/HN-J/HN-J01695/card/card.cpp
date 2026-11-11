#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[20000005];
int sum[2000005];
bool l[2000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(l,false,sizeof(l));
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(!l[a[j]]){
				q.push(a[j]);
				l[a[j]]=true;
			}
			else{
				while(q.top()!=a[j]){
					q.pop();
				}
			}
		}
		while(!q.empty()){
			int w=q.top();
			sum[w]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
