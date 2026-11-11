#include<bits/stdc++.h>
#define int long long
#define Z(x) (x*2)
#define Y(x) (x*2+1)
using namespace std;
int n,m,c,d,q,ccut;//n->地铁站数 m->线路数
int w[500005];
///////////////////堆///////////////////
struct sbb {
	int wz,z;
} sb[5000005];
int cwz[5000005],cut;
void jh(int x,int y) {
	swap(cwz[sb[x].wz],cwz[sb[y].wz]),swap(sb[x],sb[y]);
	return ;
}
void gx(int wz) {
	while(wz!=1&&sb[wz/2].z>sb[wz].z)jh(wz,wz/2),wz/=2;
	return ;
}
void sc(int wz) {
	while(Z(wz)<=cut) {
		if(Z(wz)==cut) {
			if(sb[Z(wz)].z<sb[wz].z)jh(wz,Z(wz));
			return ;
		}
		int minn=min({sb[wz].z,sb[Z(wz)].z,sb[Y(wz)].z});
		if(minn==sb[wz].z)return ;
		if(minn==sb[Z(wz)].z)jh(wz,Z(wz)),wz=Z(wz);
		else jh(wz,Y(wz)),wz=Y(wz);
	}
	return ;
}
////////////////////////dij//////////////////
/*
1->n 地铁站口
n+1->2*n 地铁站大厅
2*n+1->2*n+m 站台
*/
struct bb {
	int ne,qz;
};
vector<bb>bian[5000005];
int ans[5000005],pd[500005];
int dij(int s,int t){
	for(int i=1;i<=ccut;i++)ans[i]=1e18,pd[i]=0;
	ans[s]=0,cut++;
	sb[cut].wz=s,sb[cut].z=0,pd[s]=1;
	while(cut!=0){
		sbb wz=sb[1];
//		cout<<wz.wz<<" "<<wz.z<<'\n'; 
		jh(1,cut--),sc(1),pd[wz.wz]=0;
//		if(wz.z>=ans[t])continue;
		for(auto nwz:bian[wz.wz]){
			sbb nz;
			nz.wz=nwz.ne,nz.z=wz.z+nwz.qz;
//			cout<<nz.wz<<'\n';
			if(nz.z>=ans[nz.wz])continue;
			ans[nz.wz]=nz.z;
//			if(nz.z>=ans[t])continue;
			if(pd[nz.wz]==0)pd[nz.wz]=1,cwz[nz.wz]=++cut;
			sb[cwz[nz.wz]]=nz;
			gx(cwz[nz.wz]);
		}
	}
	return ans[t];
}
int read(){
	int pd=1,now=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')pd=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		now=now*10+ch-'0';
		ch=getchar();
	}
	return now*pd;
}
bool cmp(const bb &t1,const bb &t2){
	return t1.qz<t2.qz;
}
int mp[505][505];//相邻地铁站间最短花费时间 
struct CC{
	int zd,sj;
};
vector<CC>cc[500005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>m>>n>>d>>q;
//	cout<<q<<'\n';
	for(int i=1; i<=n; i++)cin>>w[i];
	ccut=n;
	for(int i=1; i<=m; i++) {
		int k,a,t;
		cin>>k;
		ccut++;
		for(int j=1; j<=k; j++) {
			cin>>a>>t;
			cc[a].push_back({i,t});
			bian[a].push_back({ccut,t});
			bian[ccut].push_back({a,t});
		}
	}
	for(int i=1;i<=n+m;i++)sort(bian[i].begin(),bian[i].end(),cmp);
	for(int i=1;i<=m;i++){
		dij(n+i,n);
		for(int j=i+1;j<=m;j++)mp[i][j]=mp[j][i]=ans[n+j];
	}
	for(int i=1; i<=q; i++) {
		int s,t;
		cin>>s>>t;
		int nans=1e18;
		for(auto S:cc[s])for(auto T:cc[t])nans=min(nans,mp[S.zd][T.zd]+S.sj+T.sj);
		cout<<nans+w[s]+w[t]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
ans=
32
17

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
ans=
35
16
*/
