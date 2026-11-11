#include<bits/stdc++.h>
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],q[N],h,t,las[M];
inline bool check(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(check()){
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
	}else{
		for(int i=1;i<=n;i++){
			h=1,t=0;
			for(int j=1;j<=m;j++) las[j]=0;
			for(int j=i;j<=n;j++){
				if(las[a[j]]){
					for(int k=las[a[j]]+1;k<=t;k++) las[q[k]]=0;
					t=las[a[j]];
				}else{
					las[a[j]]=++t;
					q[t]=a[j];
				}
			}
			for(int j=h;j<=t;j++) ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
