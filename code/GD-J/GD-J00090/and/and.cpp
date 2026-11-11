#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=-1e9;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	int sta=log2(mx);
	queue<int> q;
	for(int i=sta;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				int x=(a[j]>>i)&1;
				cnt+=x; //取a[j]的第i位加和 
				if(x==0){
					q.push(j);	
				}	
			} 
		}
		if(cnt>=m){
			ans+=(1<<i);
			while(!q.empty()){
				vis[q.front()]=1;
				q.pop();
			}
		}else{
			while(!q.empty()) q.pop();
		}
	}
	cout<<ans;
	return 0;
}
