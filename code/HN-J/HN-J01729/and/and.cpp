#include <bits/stdc++.h>
using namespace std;
int n,m,a[200000000],p,maxn=-1;
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&p);
		a[p]++;
		if(maxn<p)maxn=p;
	}
	for(int i=maxn;i>=1;i--){
		if(a[i]==m){cout<<i;return 0;}//ÆëÉùÁîÏÂ£¬×ÔØØ¹éÌì!!! 
	}
	for(int i=maxn;i>=1;i--){
		if(a[i])m--;
		if(!m){cout<<i;return 0;}//ÆëÉùÁîÏÂ£¬×ÔØØ¹éÌì!!! 
	}
}
