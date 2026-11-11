#include <bits/stdc++.h>
using namespace std;

const int MAXN=505,MAXM=500005;
int c,n,m,d,q,k[MAXN],a[5005][MAXN],t[5005][MAXN],w[MAXM];
bool b[5005][MAXN];

void ss(int x,int y,int &s,int ii,int jj) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k[i];j++) {
			if(b[i][j])continue;
			b[i][j]=true;
			if(a[i][j]==x) {
				s+=t[i][j];
//				cout<<"t["<<i<<"]["<<j<<"]\n";
				if(x==y)return;
				if(j+1<k[i]){
					b[i][j]=false;
				ss(a[i][j+1],y,s,i,j+1);
				b[i][j]=true;
				}else{
//					s+=t[i][k[i]];
//				cout<<"t["<<i<<"]["<<k[i]<<"]\n";
				ss(a[i+1][j],y,s,i+1,j);
				}
			} else {
				ss(a[i+1][j],y,s,i+1,j);
//				cout<<"t["<<i+1<<"]["<<j<<"]\n";
			}
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y,ans=0;
		cin>>x>>y;
//		cout<<"w["<<x<<"]\n";
		ss(x,y,ans,1,1);
//		cout<<"w["<<y<<"]\n";
		cout<<ans+w[x]+w[y];
		cout<<'\n';
		memset(b,0,sizeof(b));
	}
	return 0;
}
