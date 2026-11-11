#include<bits/stdc++.h>
using namespace std;
int a[100010],sum=0;
int c,t,n,d,e,ans=0,vis[100010];
queue<int> s;
void bfs(){
	while(!s.empty()){
		int u=s.front();
		s.pop();
		for(int i=1;i<=d&&u+i<=e;i++){
			s.push(u+i);
			vis[u+i]++;
		} 
	}
}
int main(){
	cin>>c>>t>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			memset(vis,0,sizeof(vis));
			s.push(l);
			e=r;
			vis[l]=1;
			bfs();
			cout<<l<<" "<<r<<endl;
			for(int i=1;i<=n;i++){
				cout<<vis[i]<<" ";
			}cout<<endl;
			if(vis[r]==2) ans++;
		}
	}
	cout<<ans;
	return 0;
}
