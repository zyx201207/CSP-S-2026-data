#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[100005],at1[100005][100005],P[100005][2],at2[100005][100005],atn[10005][10005],a1[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a1[i]=k
		for(int j=1;j<=k;j++){
			cin>>at1[i][j];
			cin>>at2[i][j];
		}
	}
	for(int i=1;i<=p;i++){
		cin>>P[i][0]>>P[i][1];
	}
	for(int i=1;i<=n;i++){
		int atn2[1000][1000];
		for(int j=1;j<=a1[i];j++){
			
		}
	}
	
	
	
	
	return 0;
}
