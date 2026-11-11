#include<bits/stdc++.h>
using namespace std;
long long n,m,f,a[500010],vis[300010],t[300010];
queue<long long> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(vis[a[j]]==1){
				if(q.front()==a[j]){
					while(!q.empty()){
						vis[q.front()]=0;
						q.pop();
					}
				}else{
					f=q.front();
					while(q.front()!=a[j]){
						q.push(q.front());
						q.pop();
					}	
					while(q.front()!=f){
						vis[q.front()]=0;
						q.pop();
					}
				}
			}
			vis[a[j]]=1;
			q.push(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(vis[j]==1){
				t[j]++;
				vis[j]=0;
			}
		}
		while(!q.empty()){
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
