#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	} 
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(t[a[j]]){
				for(int x=t[a[j]];x<j;++x){
					t[a[x]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=1;j<=m;++j){
			if(t[j]) ++ans[j];
			t[j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%lld ",ans[i]);
	}
	return 0;
}

