#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;//测编 地线数 站数 站最多经线 计划数 
int cnt;
int w[500005],dis[10000005];
int aa[500005],tt[500005];
int to[10000005],vail[10000005],nxt[10000005],h[10000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void add(int a,int b,int c){
	to[++cnt]=b;
	vail[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>aa[j]>>tt[j];
		} 
		for (int j=1;j<k;j++){
			for (int jj=j+1;jj<=k;jj++){
				//cout<<jj<<endl;
				add(aa[j],aa[jj],tt[j]+tt[jj]);
				add(aa[jj],aa[j],tt[j]+tt[jj]);
			}
		} 
	}
	/*for (int i=1;i<cnt;i++){
		cout<<to[i]<<" "<<vail[i]<<endl;
	}*/
	for (int i=1;i<=p;i++){
		for (int j=1;j<=cnt;j++){
			dis[j]=0x3fffffff;
		}
		int qd,zd;
		cin>>qd>>zd;
		q.push(make_pair(qd,0));
		dis[qd]=0;
		while (!q.empty()){
			k=q.top().first;
			q.pop();
			for (int j=h[k];j;j=nxt[j]){
				int o=to[j];
				if (dis[o]>(long long)(dis[k]+vail[j])){
					dis[o]=(long long)(dis[k]+vail[j]);
					//cout<<k<<" "<<o<<" "<<dis[k]<<" "<<dis[o]<<endl;
					q.push(make_pair(o,dis[o]));
				}
			}
		}
		cout<<dis[zd]+w[qd]+w[zd]<<endl;
	}
	return 0;
}
