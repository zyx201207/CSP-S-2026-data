#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long c,n,m,d,q;
long long t1[N];//Ìüµ½¿Ú 
long long k[550];
long long cnt=0;
vector<pair<long long,long long> > ids[N];
vector<pair<long long,long long> > e[2*N];
long long aaa,bbb;
long long dij(long long st,long long en){
	bool vis[2*N]={0};
	long long d[N]={0};
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> >  > q;
	for(auto v:e[st]){
		if(vis[v.first]){
			continue;
		}else{
			q.push({v.second,v.first});
		}
	}
	long long cnt2=0;
	while(!q.empty()){
		pair<long long,long long> nw=q.top();
		q.pop();
		if(vis[nw.second]){
			continue;
		}
		vis[nw.second]=1;
		if(nw.second==en){
			return nw.first;
		}
		for(auto v:e[nw.second]){
			if(vis[v.first]) continue;
			q.push({nw.first+v.second,v.first});
//			cout<<nw.second<<"-"<<v.first<<":"<<nw.first+v.second<<"\n";
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cnt=m;
	for(int i=1;i<=m;i++){
		cin>>t1[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		long long fr=0;
		for(int j=1;j<=k[i];j++){
			cin>>aaa>>bbb;
			e[aaa].push_back({++cnt,bbb+t1[aaa]});
			e[cnt].push_back({aaa,bbb+t1[aaa]});
//			cout<<aaa<<" "<<cnt<<"\n";
			for(auto a:ids[aaa]){
				e[a.first].push_back({cnt,a.second+bbb});
				e[cnt].push_back({a.first,a.second+bbb});
			}
			ids[aaa].push_back({cnt,bbb});
			if(fr==0){
				fr=cnt;
				continue;
			}
			e[fr].push_back({cnt,0});
			e[cnt].push_back({fr,0});
			fr=cnt;
		}
	}
	for(int i=1;i<=q;i++){
		long long stt,enn;
		cin>>stt>>enn;
		cout<<dij(stt,enn)<<"\n";
	}
//	for(int i=1;i<=m;i++){
//		for(auto a:ids[i]){
//			cout<<a.first<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i=1;i<=cnt;i++){
//		for(auto a:e[i]){
//			cout<<i<<"->"<<a.first<<":"<<a.second<<"\n";
//		}
//	}
	return 0;
} /*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2




*/
