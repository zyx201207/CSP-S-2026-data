#include<iostream>
#include<algorithm>
#include<cstdio>
#include<ctime>
using namespace std;
#define ll long long
#define cerr if(0)clog
struct togo{
	int a,t;
};
ll ans[510][510];
togo list[500500][25];
int listd[500500];
int w[500500];
//int used[510][510];
//int jmp[500500][20];
//int jmped[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			list[a][listd[a]]={i,t};
			listd[a]++;
		}
	}
	for(int i=0;i<=n+10;i++){
		for(int j=0;j<=n+10;j++){
			ans[i][j]=(ll)1e18;
		}
	}
	for(int j=0;j<=n+10;j++){
		ans[j][j]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<listd[i];j++){
			for(int k=0;k<j;k++){
				cerr<<"wrt: i:"<<i<<" i,j:"<<list[i][j].a<<" i,k:"<<list[i][k].a<<" t:"<<list[i][j].t+list[i][k].t<<'\n';
				ans[list[i][j].a][list[i][k].a]=min(
					ans[list[i][j].a][list[i][k].a],
					list[i][j].t+(ll)list[i][k].t
				);
				ans[list[i][k].a][list[i][j].a]=ans[list[i][j].a][list[i][k].a];
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr.width(4);
//			if(ans[i][j]>1000000)
//			cerr<<"inf";
//			else
//			cerr<<ans[i][j];
//		}
//		cerr<<'\n';
//	}
	for(int jmp=1;jmp<=n;jmp++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=min(ans[i][j],ans[i][jmp]+ans[jmp][j]);
			}
		}
	}
	for(int i=0;i<q;i++){
		int a,b;
		cin>>a>>b;
		ll ret=(ll)1e18;
//		ret*=ret;
		for(int j=0;j<listd[a];j++){
			for(int k=0;k<listd[b];k++){
//				if(used[list[i][j].a][list[i][k].a])continue;
				ret=min(ret,ans[list[a][j].a][list[b][k].a]+list[a][j].t+list[b][k].t);
				cerr<<ans[list[a][j].a][list[b][k].a]<<' '<<list[a][j].t<<' '<<list[b][k].t<<'\n';
			}
		}
		cout<<ret+w[a]+w[b]<<'\n';
	}
	clog<<clock();
}
