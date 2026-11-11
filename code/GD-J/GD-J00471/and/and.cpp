#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200007],ans;
bool vis[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=31;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&((1<<i)&a[j]))
				sum++;
		if(sum<m) continue;
		ans|=(1<<i);
		for(int j=1;j<=n;j++)
			if(!vis[j]&&!((1<<i)&a[j]))
				vis[j]=true;
	}
	cout<<ans;
	return 0;
}
