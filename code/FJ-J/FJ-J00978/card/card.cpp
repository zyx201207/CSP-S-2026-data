#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
int a[500001],ans[300001];
bool vis[300001];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof vis);
		for(int j=i;j<n;j++){
			if(vis[a[j]]){
				while((!s.empty())&&(s.top()!=a[j])){
					s.pop();
				}
				s.pop();
				vis[a[j]]=0;
			}
			s.push(a[j]);
			vis[a[j]]=1;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
