#include<bits/stdc++.h>
using namespace std;
int a[200005],vis[200005],tt[2000005];
deque<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				q.push_back(a[j]);
				vis[a[j]]=1;
			}else{
				while(q.back()!=a[j]) vis[q.back()]=0,q.pop_back();
			}
		}
		while(!q.empty()){
			tt[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<tt[i]<<' ';
	}
	return 0;
} 
