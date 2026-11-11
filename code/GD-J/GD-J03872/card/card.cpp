#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,cnt,cnt2,nn;
int ans[N],b[N],nxt[N],fa[N],tmp[N];
int flg[N],lll[N];
bool zt[5001][3001];
bool zt2[200001][101];
struct node{
	int a,sum;
}a[N],bbk[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int op=1,t=0;
	for(int i=1;i<=n;i++) {
		cin>>tmp[i];
	}
	for(int i=n,j=1;i>=1;i--,j++) lll[i]=tmp[j];
	nn=n;
	for(int i=2;i<=n;i++) {
		if(tmp[i]==tmp[i-1]) {
			op++;
		}
		else{
			bbk[++t]={tmp[i-1],op};
			op=1;
		}
	}
	bbk[++t]={tmp[n],op};
	n=t;
	for(int i=n,j=1;i>=1;i--,j++) a[i]=bbk[j];
	// for(int i=1;i<=n;i++) cout<<a[i].a<<" "<<a[i].sum<<"\n";
	if(n<=5000 && m<=3000) {
		for(int i=1;i<=n;i++) {
			// cout<<"i:"<<i<<"\n";
			for(int j=1;j<=m;j++) zt[i][j]=zt[i-1][j];
			if(nxt[a[i].a]) {
				int id=nxt[a[i].a];
				for(int j=1;j<=m;j++) {
					zt[i][j]=zt[id][j];
				}
			}
			else{
				zt[i][a[i].a]=1;
				if(!nxt[a[i].a]) nxt[a[i].a]=i;
			}
			for(int j=1;j<=m;j++) {
				if(zt[i][j]) {
					// cout<<j<<" ";
					ans[j]+=a[i].sum;
				}
			}
			// cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(n<=200000 && m<=100) {
		for(int i=1;i<=n;i++) {
			// cout<<"i:"<<i<<"\n";
			for(int j=1;j<=m;j++) zt2[i][j]=zt2[i-1][j];
			if(nxt[a[i].a]) {
				int id=nxt[a[i].a];
				for(int j=1;j<=m;j++) {
					zt2[i][j]=zt2[id][j];
				}
			}
			else{
				zt2[i][a[i].a]=1;
				if(!nxt[a[i].a]) nxt[a[i].a]=i;
			}
			for(int j=1;j<=m;j++) {
				if(zt2[i][j]) {
					// cout<<j<<" ";
					ans[j]+=a[i].sum;
				}
			}
			// cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=nn;i++) {
		if(!flg[lll[i]]) {
			if(i!=1) cout<<i-1<<" ";
			flg[lll[i]]=1;
		}
	} 
	cout<<nn<<"\n";
}
