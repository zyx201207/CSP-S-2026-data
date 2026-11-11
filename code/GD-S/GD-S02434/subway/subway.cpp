#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,zztime;
struct xianlu{
	int k;
	int a[500005],t[500005];
}xl[505];
struct chezhan{
	int w;
	int xianlu;
	int xl[25],t[25];
}cz[500005];

void gogogo(int now,int ntime){
	for(int i=0;i<cz[now].xianlu;i++){
		for(int j=0;j<xl[cz[now].xl[i]].k;j++){
			ntime+=cz[x].t[i];
			if(xl[cz[x].xl[i]].a[j]==y){
				ntime+=xl[cz[x].xl[i]].t[j];
				zztime=min(zztime,ntime);
				continue;
			}
			if(cz[xl[cz[x].xl[i]].a[j]].xianlu>1){
				ntime+=xl[cz[x].xl[i]].t[j];
				gogogo(xl[cz[x].xl[i]].a[j],ntime);
			}
		}
	}
		
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>cz[i].w;
	}
	for(int i=0;i<n;i++){
		cin>>xl[i].k;
		for(int j=0;j<xl[i].k;j++){
			cin>>xl[i].a[j]>>xl[i].t[j];
			cz[xl[i].a[j]].xl[cz[xl[i].a[j]].xianlu++]=i;
			cz[xl[i].a[j]].t[cz[xl[i].a[j]].xianlu++]=xl[i].t[j];
		}
	}
	for(int r=0;r<q;r++){
		zztime=100000000;
		cin>>x>>y;
		gogogo(x,cz[x].w+cz[y].w);
		cout<<zztime;
	}
	return 0;
}
