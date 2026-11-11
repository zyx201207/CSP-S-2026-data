#include<bits/stdc++.h>
using namespace std;
struct rr{
	int bh;
	long long tme;
}r[2000];
int c,n,m,d,q,cnt,cnts;
int w[500500],k[1000],a[510][200500],t[510][200500];
long long sumn[500][2000];
long long f[600][600];
int u[500500][25],ul[500500];
bool pd[2000];
int x,y;
int cll(){
	int ans=r[1].bh;
	cnts--;
	r[1].bh=0;r[1].tme=600000000000000;
	int p=1;
	while(r[p*2].bh!=0||r[p*2+1].bh!=0){
		if((r[p*2].tme<=r[p*2+1].tme&&r[p*2].bh!=0)||(r[p*2+1].bh==0)){
			if(r[p*2].tme<r[p].tme){
				swap(r[p*2],r[p]);
				p=p*2;
			}
			else break;
		}
		else {
			if(r[p*2+1].tme<r[p].tme){
				swap(r[p*2+1],r[p]);
				p=p*2+1;
			}
			else break;
		}
	}
	return ans;
}
void qll(int bhk,long long tmek){
	r[++cnt].bh=bhk;
	r[cnt].tme=tmek;
	cnts++;
	int p=cnt;
	while(p/2!=0){
		if(r[p].tme<r[p/2].tme||r[p/2].bh==0){
			swap(r[p/2],r[p]);
			p=p/2;
		}
		else {
			 break;
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int o=1;o<=k[i];o++){
			cin>>a[i][o]>>t[i][o];
			ul[a[i][o]]++;
			u[a[i][o]][ul[a[i][o]]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++)f[i][o]=600000000000000;
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
		qll(i,0);
		while(cnts>0){
			int v=cll();
			if(pd[v]==1)continue;
			pd[v]=1;
			for(int o=1;o<=k[v];o++){
			for(int p=1;p<=ul[a[v][o]];p++){
				if(u[a[v][o]][p]==v)continue;
				if(f[i][u[a[v][o]][p]]>f[i][v]+t[v][a[v][o]]+t[u[a[v][o]][p]][a[v][o]]){
					f[i][u[a[v][o]][p]]=f[i][v]+t[v][a[v][o]]+t[u[a[v][o]][p]][a[v][o]];
					qll(u[a[v][o]][p],f[i][u[a[v][o]][p]]);
				}
			}
		}
		}
		cnt=0;cnts=0;
		for(int o=1;o<=2*n+1;o++){
			r[o].tme=0;
			r[o].bh=0;
			pd[o]=0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long minn=600000000000000;
		for(int p=1;p<=ul[y];p++){
			for(int o=1;o<=ul[x];o++){
			minn=min(minn,w[x]+w[y]+t[u[x][o]][x]+f[u[y][p]][u[x][o]]+t[u[y][p]][y]);
		}
		}
		cout<<minn<<endl;
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
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
