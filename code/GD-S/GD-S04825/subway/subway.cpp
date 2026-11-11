#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q2,w[500010],k[500010],a[500010],t[500010],p[500010][50],q[500010][50]\
,s[500010],e[510][500010],x,y;
long long b[510][510],ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q2;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			p[a[j]][++s[a[j]]]=i;
			q[a[j]][s[a[j]]]=t[j];
			e[i][a[j]]=t[j];
		}
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=m;i++){
		if(s[i]>=2){
			for(int j=1;j<=s[i];j++){
				for(int l=j+1;l<=s[i];l++){
					b[p[i][j]][p[i][l]]=q[i][j]+q[i][l];
					b[p[i][l]][p[i][j]]=q[i][j]+q[i][l];
//					cout<<"b["<<p[i][j]<<"]["<<p[i][l]<<"]="<<q[i][j]+q[i][l]<<endl;
				}
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i][l]+b[l][j]<b[i][j]&&i!=l&&l!=j&&i!=j){
					b[i][j]=b[i][l]+b[l][j];
				}
			}
		}
	}
	while(q2--){
		cin>>x>>y;
		ans=LONG_LONG_MAX;
		for(int i=1;i<=s[x];i++){
			for(int j=1;j<=s[y];j++){
				if(p[x][i]==p[y][j]){
					ans=min(ans,w[x]+w[y]+e[p[x][i]][x]+e[p[y][j]][y]+0ll);
//					cout<<w[x]<<"+"<<w[y]<<"+"<<e[p[x][i]][x]<<"+"<<e[p[y][j]][y]<<"+0"<<endl;
				}else{
					ans=min(ans,w[x]+w[y]+e[p[x][i]][x]+e[p[y][j]][y]+b[p[x][i]][p[y][j]]);
//					cout<<w[x]<<"+"<<w[y]<<"+"<<e[p[x][i]][x]<<"+"<<e[p[y][j]][y]<<"+"<<b[p[x][i]][p[y][j]]<<endl;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*Oct31==Dec25?

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
