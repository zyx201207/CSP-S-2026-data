#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];//kou->ting
int k[505];
int a[505][50005];
int t[505][50005];
int x[100005];
int y[100005];


int s[50005][505]; 
 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]][i]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	
	cout<<"please AC! qwq\n";
	
	return 0;
} 

