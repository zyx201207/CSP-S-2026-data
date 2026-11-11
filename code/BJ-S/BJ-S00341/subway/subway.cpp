#include <bits/stdc++.h>
using namespace std;
long long t1[100010],t2[10010][10010],k[10010][10010];
long long c,n,m,d,q,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>t1[i];
	for(int i=1;i<=n;i++){
		cin>>k[i][1];
		for(int j=2;j<=k[i][1];j++){
			cin>>k[i][j]>>t2[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		long long l=0;
		long long mi=0;
		cin>>x>>y;
		for(int i1=1;i1<=n;i1++){
			for(int j=1;j<=k[i1][1];j++){
				if(x==k[i1][j]){
					l=i1;
				
				}
			}
		}
		for(int a=1;a<=n;a++){
			for(int j=1;j<=k[l][1];j++){
				mi=t1[j]+t2[l][j]+mi;
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}
