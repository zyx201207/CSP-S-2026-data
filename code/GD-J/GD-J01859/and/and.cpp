#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	vector<bool>vis(n);
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=1<<30;i>0;i>>=1){
		int c1=0;
		for(int j=0;j<n;j++)if(!vis[j]&&(a[j]&i))c1++;
		if(c1>=m){
			ans|=i;
			for(int j=0;j<n;j++)if(!vis[j]&&!(a[j]&i))vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
} 
