#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,T,m,a[N],ans[N],b[N],f[N],cnt;
void work(int st){
	fill(f+1,f+m+1,0);
	T=0;
	for(int i=st;i<=n;i++){
		if(f[a[i]]){
			T=f[a[i]]-1;
		}
		b[++T]=a[i];
		f[a[i]]=T;
		for(int j=1;j<=m;j++){
			if(f[j]>=f[a[i]] and j!=a[i]) f[j]=T+1;
		}
	}
	for(int i=1;i<=T;i++){
		ans[b[i]]++;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) work(i);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
