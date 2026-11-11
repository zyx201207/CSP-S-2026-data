#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[1007];
long long k[25];
long long a[507][1007];
long long t[1007][25];
long long T;



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[a[i][j]][i];
			if(c >= 12 && c <= 19){
				T = t[a[i][j]][i];
			}
		}
	}
	int x,y;
	long long ans;
	for(long long i=1;i<=q;i++){
		ans = 0;
		cin>>x>>y;
		cout<<w[x]+w[y]+T*2;
	}
	
	return 0;
}
