#include <bits/stdc++.h>
using namespace std;
#define gc getchar
inline int rd(){
	int r_x=0,r_c=0;
	r_c=gc();
	while(!isdigit(r_c)){
		r_c=gc();
	}
	while(isdigit(r_c)){
		r_x=(r_x<<3)+(r_x<<1)+(r_c^48);
		r_c=gc();
	}
	return r_x;
}
long long sid,n,m,d,q,a[500005],len[500005],f[505][505],aa,bb,cc,zym;
pair<long long,long long> line[500005][21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	sid=rd();
	n=rd();
	m=rd();
	d=rd();
	q=rd();
	for(int i=1;i<=m;++i){
		a[i]=rd();
	}
	for(int i=1;i<=n;++i){
		aa=rd();
		for(int j=1;j<=aa;++j){
			bb=rd();
			cc=rd();
			++len[bb];
			line[bb][len[bb]]=make_pair(i,cc);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			f[i][j]=114514114514114514;
			if(i==j){
				f[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<len[i];++j){
			for(int k=2;k<=len[i];++k){
				aa=line[i][j].first;
				bb=line[i][k].first;
				f[aa][bb]=min(f[aa][bb],line[i][j].second+line[i][k].second);
				f[bb][aa]=f[aa][bb];
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		aa=rd();
		bb=rd();
		zym=114514114514114514;
		for(int j=1;j<=len[aa];++j){
			for(int k=1;k<=len[bb];++k){
				zym=min(zym,a[aa]+a[bb]+line[aa][j].second+line[bb][k].second+f[line[aa][j].first][line[bb][k].first]);
			}
		}
		cout<<zym<<endl;
	}
	return 0;
}

