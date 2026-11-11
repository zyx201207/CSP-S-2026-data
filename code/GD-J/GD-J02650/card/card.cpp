#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N],fw[M],ans[M];
bool fl[M];
int now_in[M],t=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500){
		for(int p=1;p<=n;p++){
		for(int i=1;i<=m;i++) now_in[i]=fl[i]=fw[i]=0; 
		for(int i=p;i<=n;i++){
			int ai=a[i];
			if(fl[ai]){
				int l=fw[ai]+1;
				for(int j=l;j<=t;j++) fl[now_in[j]]=0;
				t=l-1;
			}else fl[ai]=1,fw[ai]=++t,now_in[t]=ai;
		}
		for(int i=1;i<=m;i++) if(fl[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) fw[a[i]]=i;
	for(int i=1;i<=m;i++) cout<<fw[i]<<" ";
	return 0;
}
