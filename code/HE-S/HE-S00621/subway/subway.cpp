#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
long long w[M];
long long read(){
	long long k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
struct node{
	int v;long long tim;
};
int n,m,d,q;
long long f[1010][1010];
void solve(){
		for(int len=3;len<=m;len++)
			for(int l=1,r;l<=m;l+=1){
				r=l+len-1;
				if(l!=r)
					for(int tt=1;tt<=m;tt++)
						if(tt!=l&&tt!=r)
							f[l][r]=f[r][l]=min(f[l][r],f[l][tt]+f[tt][r]);
		}
	for(int i=1,u,v;i<=q;i++){
		u=read();v=read();
		cout<<f[u][v]+w[u]+w[v]<<'\n';
	}
}
int a[M];long long qwq[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n;cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j)f[i][j]=1000000000000000;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>qwq[j];
		}
		
		for(int j=1;j<=k;j++)
			for(int l=1;l<=k;l++){
				if(j!=l)
				f[a[j]][a[l]]=min(qwq[j]+qwq[l],f[a[j]][a[l]]);
			}
//				cout<<"qwq"<<'\n';
//				cout<<"EnD"<<'\n';	
	}
	solve();
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
