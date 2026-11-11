#include<iostream>
using namespace std;
int c,n,m,d,q;
int w[500001],k[501],x[500001],y[500001],a[501][500001],t[501][500001],T[500001],o=10000000,v[500001];
int z(int d,int e,int f,int g){
	if(d==e&&f<o){
		o=f;
	}
	for(int i=1;i<=n;i++){
		int b=0,l;
		if(g!=i){
			b=1;
			f+=t[i][d];
			l=g;
			g=i;
		}
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==d){
				for(int s=1;s<=k[i];s++){	
					if(j-s>=1&&v[a[i][j-s]]==0){
						v[a[i][j-s]]=1;
						z(a[i][j-s],e,f+t[i][j-s],g);
						v[a[i][j-s]]=0;
					}
					if(j+s<=k[i]&&v[a[i][j+s]]==0){
						v[a[i][j+s]]=1;
						z(a[i][j+s],e,f+t[i][j+s],g);
						v[a[i][j+s]]=0;
					}
				}
			}
		}
		if(b==1){
			f-=t[i][d];
			g=l;
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		v[x[i]]=1;
		z(x[i],y[i],w[x[i]]+w[y[i]],0);
		T[i]=o;
		o=10000000;
	}
	for(int i=1;i<=q;i++){
		cout<<T[i]<<endl;
	}
	return 0;
}
