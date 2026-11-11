#include<bits/stdc++.h>
#define N 200050
using namespace std;
int n,m,ans;
int a[N];
int cnt[35],w[N];
vector<int>h[N];
priority_queue<pair<int,int> >q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int b=a[i],x=1;
		while(b!=0){
			if(b%2)h[x].push_back(i),cnt[x]++;
			x++;
			b/=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(cnt[i]>=m){
			for(int j=0;j<h[i].size();j++){
				w[h[i][j]]+=(1<<i);
				q.push({w[h[i][j]],h[i][j]});
			}
			if(cnt[i]==m)break;
		}
	}
	while(!q.empty()){
		int u=q.top().first,x=q.top().second;
		q.pop();
//		cout<<a[x]<<"\n";
		if(u!=w[x])continue;
		if(m==0)break;
		m--;
		if(ans==0)ans=a[x];
		ans&=a[x];
	}
	cout<<ans;
	return 0;
}
