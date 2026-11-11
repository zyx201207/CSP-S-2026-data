#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int c,n,m,q,d,w[N],k,t[505][N],b,x[N],y[N],tr[N];
bool a[505][N],r[N],e[100005],f[100005];
int fin(int xi,int yi,int su=0){
	if(xi==yi) return t[su][xi];
	long long mi=100000005,no;
	for(int j=1;j<=n;j++){
		if(a[j][xi]&&!f[j]){
			f[j] = 1;
			for(int i=1;i<=m;i++){
				if(a[j][i]&&!e[i]){
					e[i]=1;
					no = fin(i,yi,j)+t[su][xi]+t[j][xi];
					if(no<mi) mi=no;
					e[i]=0;
					//printf("%d %d %d ",xi,i,j); 
				}
			}
			f[j]=0;
		}
	}
	//printf("%d\n",mi);
	return mi;
}
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		while(k){
			cin>>b;
			cin>>t[i][b];
			a[i][b] = 1;
			k--;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		tr[i]+=w[x[i]]+w[y[i]]; 
		for(int j=1;j<=n;j++){
			if(a[j][x[i]]&&a[j][y[i]]){
				tr[i]+=t[j][x[i]]+t[j][y[i]];
				r[i]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		if(!r[i]) tr[i]+=fin(x[i],y[i]);
		cout<<tr[i]<<endl;
	}
	return 0;
}
