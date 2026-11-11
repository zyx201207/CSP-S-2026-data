#include<bits/stdc++.h>
using namespace std;
int const N=5e5+100;
long long const bb=1e18+10;
long long l[600][600];
long long c,n,m,d,q;
long long w[N];
long long K[600];
long long t[N][25];
long long a[N][25];
void read(long long &x){
	x=0;
	char cc=getchar();
	long long f=1;
	while(cc<'0'||cc>'9'){
		if(cc=='-')f=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		x=(x<<3)+(x<<1)+cc-'0';
		cc=getchar();
	}
	x*=f;
	return ;
}
int main(){
	long long x,y;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		read(K[i]);
		for(int j=1;j<=K[i];j++){//用点记 
			read(x);read(y);
			++a[x][0];
			a[x][a[x][0]]=i;//a[i][0]为i点有几条地铁站; 
			t[x][a[x][0]]=y;
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<":";
//		for(int j=1;j<=a[i][0];j++){
//			cout<<a[i][j]<<"_"<<t[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=bb;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i][0];j++){
			for(int k=1;k<=a[i][0];k++){
				if(k==j)l[a[i][j]][a[i][k]]=0;
				else l[a[i][j]][a[i][k]]=min(l[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
			}
		}
	}

	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(l[i][k]==bb||l[k][j]==bb)continue;
				l[i][j]=min(l[i][j],l[i][k]+l[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(l[i][j]==bb)cout<<-1;
//			else cout<<l[i][j];
//			cout<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<l[1][2]<<" "<<l[2][1]<<"__________";
	long long ans=LONG_LONG_MAX;
	for(int o=1;o<=q;o++){
		ans=bb;
		read(x);read(y);
		for(int i=1;i<=a[x][0];i++){
			for(int j=1;j<=a[y][0];j++){
				if(l[a[x][i]][a[y][j]]<bb)
				ans=min(ans,l[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
			}
		}
//		cout<<ans<<"__________"<<endl;	
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
