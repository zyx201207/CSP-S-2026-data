#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
int k[N];
int kk[N][N];
int xy[N][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>kk[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xy[i][0]>>xy[i][1];
	}
	printf("ЖЋзг"); 
	return 0;
}
