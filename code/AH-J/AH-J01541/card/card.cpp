#include "bits/stdc++.h"
using namespace std;
#define LL long long
const int N=3e5+5;
int t[N],a[N],ans[N];
bool vis[N];
int n,m;
int main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%d",&a[i]);
	int k=1,r;
	while (k<=n){
		r=k+1;
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		t[a[r-1]]=r-1;
		ans[a[r-1]]++;
		vis[r-1]=1;
		while (r<=n){
			ans[a[r]]++;
			vis[r]=1;
			if (t[a[r]]) {
				for (int i=t[a[r]];i<r;i++){
					if (vis[i]) ans[a[i]]--,vis[i]=0,t[a[i]]=0;
				}
				t[a[r]]=r++;
			}
			else t[a[r]]=r++;
		}
//		printf ("%d ",k);
//		for (int i=1;i<=m;i++) printf ("%d ",ans[i]);
//		cout<<'\n';

		k++;
	}
	for (int i=1;i<=m;i++){
		printf ("%d ",ans[i]);
	}
	cout<<'\n'; 
	return 0;
}

