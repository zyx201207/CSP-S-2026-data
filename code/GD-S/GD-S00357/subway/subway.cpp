#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510;
const int maxk=510;
const int maxq=510;
int c,n,m,d,q,w[maxn],k[maxn],a[maxn][maxk],t[maxn][maxk],x[maxq],y[maxq],sum;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){		
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
		sum+=w[x[r]]+w[y[r]];
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x[r]){
					flag1++;
					sum+=t[i][j];
				}if(a[i][j]==y[r]){
					flag2++;
					sum+=t[i][j];
				}
			}if(flag1&&flag2){
				cout<<sum;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
