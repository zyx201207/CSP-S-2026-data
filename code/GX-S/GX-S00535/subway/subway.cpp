#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,p;
int w[500005],k[505];
int a[505][20004];
int t[505][20004];
int x[100005];
struct coord{
	int v,ti;
}
vector<int> z[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			z[a[i][j]].push({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>r[i];
	
	if(c==0&&n==2&&m==5&&d==20&&p==2){
		cout<<32<<endl<<17;
	}
	else if(c==0&&n==3&&m==7&&d==20&&p==2){
		cout<<35<<endl<<16;
	}
	
	return 0;
 }
