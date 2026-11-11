#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5;
int n,m;
int a[MAXN+5],t[MAXN+5],p[MAXN+5],ans[MAXN+5];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]<a[i-1]) f=false;
	}
	if(f){
		for(int i=1;i<=n;++i) for(int j=a[i];j<=m;++j) ++ans[j];
	}else{
		for(int i=1;i<=n;++i){
			int cnt=0;
			fill(p+1,p+m+1,0);
			for(int j=i;j<=n;++j){
				if(!p[a[j]]) t[++cnt]=a[j],p[a[j]]=cnt;
				else while(t[cnt]!=a[j]) p[t[cnt--]]=0;;
			}
			for(int j=1;j<=cnt;++j) ++ans[t[j]];
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
}
