#include<bits/stdc++.h>
using namespace std;
string w,s;
long long n,ans,an,m,c[10000001],a[10000001],b[10000001];
bool cop(long long x){
	if(x==m){
		an=INT_MAX;
		for(int i=1; i<=x; i++){
			an=min(an,b[i]);
		} 
		ans=max(ans,an);
		return 0;
	}
	else{
		for(int i=1; i<=n; i++){
			if(c[i]==0){
				c[i]=1;
				b[x+1]=a[i];
				cop(x+1);
				c[i]=b[x+1]=0;
			}
		}
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
	}
	cop(0);
	printf("%lld",ans);
	return 0;
}

