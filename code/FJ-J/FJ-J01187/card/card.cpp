#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int cnt;
int l[N];
int r[M];
int ans[M];
int q,p;
int f[M];
int t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(r[a[i]]) l[i]=r[a[i]]-i;
		if(!r[a[i]]) r[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		p=i,q=n;
		memset(f,0,sizeof(f));
		f[a[i]]=1;
		t=0;
		ans[a[i]]++;
		while(q>p){
			if(l[p]&&q-p>=l[p]){
			    p=p+l[p];
			}
			else{
				++p;
				if(!f[a[p]]) ans[a[p]]++,t++,f[a[p]]=1;
			}
			if(t==m) p=n;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
