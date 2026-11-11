#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,now,a[N],vis[N],cnt[N];
stack<int>s; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
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
		while(s.size()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" "; 
	}
	return 0;
}
