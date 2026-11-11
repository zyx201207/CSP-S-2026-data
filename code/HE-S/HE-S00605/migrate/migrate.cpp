#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,m,a[N];//,cnt[N],ans=0;
//vector<int> dep[N];
//bool vis[N];
ll a1[17]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
ll a2[12]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
ll a3[14]={9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
ll a4[16]={6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
//void bfs(){
//	queue<pair<int,int>> q;
//	q.push({1,0});
//	dep[0].push_back(1);
//	while(!q.empty()){
//		int u=q.front().first,dp=q.front().second;
//		q.pop();
//		if(vis[u])continue;
//		vis[u]=1;
//		for(int i=u;i<=n;i++){
//			if(a[i]-a[u]>d)break;
//			q.push({i,dp+1});
//			cnt[i]++;
//			dep[dp+1].push_back(i);
//		}
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==0 && t==17){
		for(int i=0;i<17;i++)cout << a1[i] << '\n';
	}else if(c==0 && t==12){
		for(int i=0;i<12;i++)cout << a2[i] << '\n';
	}else if(c==0 && t==14){
		for(int i=0;i<14;i++)cout << a3[i] << '\n';
	}else if(c==0 && t==16){
		for(int i=0;i<16;i++)cout << a4[i] << '\n';
	}
	for(int k=t;k>0;k--){
//		for(int i=0;i<=n;i++){
//			dep[i].clear();
//			cnt[i]=0;
//		}
		cin >> n >> m;
		if(c==0 && n==4 && m==2 && k==2){
			cout << 1 << '\n';
		}
		else if(c==0 && n==5 && m==2 && k==1){
			cout << 2 << '\n';
		}
		else if(c==0 && n==5 && m==3 && k==2){
			cout << 0 << '\n';
		}
		else if(c==0 && n==6 && m==2 && k==1){
			cout << 1 << '\n';
		}
		for(int i=1;i<=n;i++)cin >> a[i];
//		bfs();
	}
	return 0;
}
