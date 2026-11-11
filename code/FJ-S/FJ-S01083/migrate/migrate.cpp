#include<bits/stdc++.h>
using namespace std;
long long c,t,ans,n,d;
long x[1000005],s[1000005];
bool one(int a,int b){
	if(s[a]>=b){
		if(s[a]>=b&&s[a]-1<=b) return 1;
	}
	else if(s[a]>s[s[a]-1]) return one(s[a],b);
	return 0;
}
bool two(int a,int b){
	if(s[a]>a+1&&one(a,s[a]-1)&&one(s[a]-1,b)&&!one(s[a]-2,b)){
		ans++;
		return 1;
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;;j++){
				if(x[i+j]-x[i]>d||i+j>n) break;
				s[i]=i+j;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				two(i,j);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}