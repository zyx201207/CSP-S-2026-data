#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],vis[N],dis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>s;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}
			}else {
				s.push(a[j]);
				vis[j]=1;
			}
		}
		while(s.size()){
			dis[s.top()]++;
			vis[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
} 
