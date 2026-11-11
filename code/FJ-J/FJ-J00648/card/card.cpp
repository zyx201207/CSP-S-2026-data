#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
const int M=3*1e5+5;
ll n,m;
ll a[N];
ll vis[M];
ll vis2[M];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!s.empty()){
			s.pop();
		}
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}else{
				vis[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			vis2[i]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis2[i]<<' ';
	}
	return 0;
}