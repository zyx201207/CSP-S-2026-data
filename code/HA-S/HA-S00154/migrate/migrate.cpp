#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,dd;
int x[200010],d[200010],ans[200010];
int bfs(int check){
	queue<int>q;
	q.push(check);
	for(int i=check;i<=n;i++){
		d[i]=1e10;
		ans[i]=0;
	}
	d[check]=0;
	ans[check]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=t+1;i<=n;i++){
			if(abs(x[i]-x[t])<=dd){
				if(d[t]+1<d[i]){
					q.push(i);
					d[i]=d[t]+1;
					ans[i]=1;
				}
				else if(d[t]+1==d[i]){
					ans[i]++;
					q.push(i);
				}
			}
			else{
				break;
			}
		}
	}
	int sum=0;
	for(int i=check;i<=n;i++){
		if(ans[i]==2){
			sum++;
		}
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>dd;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int sum=0;
		for(int i=1;i<=n-3;i++){
			sum+=bfs(i);
//			cout<<sum<<' ';
		}
		cout<<sum<<'\n';
	}
	return 0;
}
