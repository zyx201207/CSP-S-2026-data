#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1000000000000000;
bool book[505];
int c,n,m,d,q;
long long dis[505];
int w[500005];
long long mmp[505][505];
vector<pair<int,int> >mps[500005];
vector<pair<int,long long> >mp[505];
pair<long long,int>kkksc03[500005];
bool cmp(pair<long long,int>a,pair<long long,int>b){
	return a.first<b.first;
}
long long dij(int st,int ed){
	for(int i=1;i<=n;i++){
		dis[i]=MAXN;
		book[i]=false;
	}
	int l=1,r=0;
	for(int i=0;i<=mps[st].size();i++){
		int now=mps[st][i].first;
		dis[now]=mps[st][i].second;
		for(int j=0;j<mp[now].size();j++){
			r++;
			kkksc03[r]={mp[now][j].second+dis[now],mp[now][j].first};
		}
	}
	int manbo[505],op=0;
	long long road[505];
	for(int i=0;i<mps[ed].size();i++){
		op++;
		manbo[i]=mps[ed][i].first;
		road[i]=mps[ed][i].second;
	}
	while(l<=r){
		sort(kkksc03+l,kkksc03+r+1,cmp);
		long long dd=kkksc03[l].first;
		int nxt=kkksc03[l].second;
		l++;
		dis[nxt]=min(dis[nxt],dd);
		if(book[nxt])continue;
		book[nxt]=true;
		for(int i=0;i<mp[nxt].size();i++){
			r++;
			kkksc03[r]={mp[nxt][i].second+dis[nxt],mp[nxt][i].first};
		}
	}
	long long ans=MAXN;
	//for(int i=0;i<=op;i++)cout << dis[manbo[i]] << ' ';
	for(int i=0;i<op;i++){
		//cout << dis[manbo[i]]+1ll*mps[ed][i].second << ' ';
		ans=min(dis[manbo[i]]+road[i],ans);
	}
	return ans;
}
long long dij0(int st,int ed){
	for(int i=1;i<=n;i++){
		dis[i]=MAXN;
		book[i]=false;
	}
	int l=1,r=0;
	for(int i=0;i<=mps[st].size();i++){
		int now=mps[st][i].first;
		dis[now]=mps[st][i].second;
		for(int j=0;j<mp[now].size();j++){
			r++;
			kkksc03[r]={mp[now][j].second+dis[now],mp[now][j].first};
		}
	}
	int manbo[505],op=0;
	long long road[505];
	for(int i=0;i<mps[ed].size();i++){
		op++;
		manbo[i]=mps[ed][i].first;
		road[i]=mps[ed][i].second;
	}
	while(l<=r){
		sort(kkksc03+l,kkksc03+r+1,cmp);
		long long dd=kkksc03[l].first;
		int nxt=kkksc03[l].second;
		l++;
		dis[nxt]=min(dis[nxt],dd);
		if(book[nxt])continue;
		book[nxt]=true;
		for(int i=0;i<mp[nxt].size();i++){
			r++;
			kkksc03[r]={mp[nxt][i].second+dis[nxt],mp[nxt][i].first};
		}
	}
	long long ans=MAXN;
	//for(int i=0;i<=op;i++)cout << dis[manbo[i]] << ' ';
	for(int i=0;i<op;i++){
		//cout << dis[manbo[i]]+1ll*mps[ed][i].second << ' ';
		ans=min(dis[manbo[i]]+road[op-i-1],ans);
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int k,kk,kkk;
		cin >> k;
		for(int i=1;i<=k;i++){
			cin >> kk >> kkk;
			mps[kk].push_back({i,kkk});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mmp[i][j]=10000000000;
	for(int i=1;i<=m;i++){
		for(int j=0;j<mps[i].size()-1;j++){
			for(int k=j+1;k<mps[i].size();k++)mmp[mps[i][j].first][mps[i][k].first]=min(mmp[mps[i][j].first][mps[i][k].first],1ll*(mps[i][j].second+mps[i][k].second));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(mmp[i][j]==10000000000)continue;
		mp[i].push_back({j,mmp[i][j]});
		mp[j].push_back({i,mmp[i][j]});
	}
	if(c==0){
		while(q--){
			int a,b;
			cin >> a >> b;
			long long mm=dij0(a,b);
			cout << 1ll*(w[a]+w[b])+mm << endl;
			//for(int i=1;i<=n;i++)cout << dis[i] << ' ';
		}
	}
	else while(q--){
		int a,b;
		cin >> a >> b;
		long long mm=dij(a,b);
		cout << 1ll*(w[a]+w[b])+mm << endl;
		//for(int i=1;i<=n;i++)cout << dis[i] << ' ';
	}
	return 0;
}
/*
n<=500
tmd,smdt,lzbxl.
*/
