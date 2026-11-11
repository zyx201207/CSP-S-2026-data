#include<cstdio>
#include<vector>
#include<algorithm>
#include<fstream>
long long max(long long a,long long b){
	return a>b?a:b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long x,y,get;
	scanf("%lld%lld",&x,&y);
	std::vector<long long> t(x+1,0),w(x+1,0),z(x+1,0);
	for(long long a=1;a<=x;a++){
		scanf("%lld",&t[a]);
	}
	std::sort(t.begin()+1,t.begin()+x+1);
//	for(long long a=1;a<=x;a++){
//		printf("%lld ",t[a]);
//	}
//	printf("\n");
	for(long long a=2;a<=x;a++){
		w[a]=t[a]-t[a-1];
	}
//	for(long long a=1;a<=x;a++){
//		printf("%lld ",w[a]);
//	}
//	printf("\n");
	for(long long a=2;a<=x;a++){
		z[a]=z[a-1]+w[a]*(a-1);
	}
//	for(long long a=1;a<=x;a++){
//		printf("%lld ",z[a]);
//	}
//	printf("\n");
	get=std::upper_bound(z.begin()+1,z.begin()+x+1,y)-1-z.begin();
	printf("%lld",get);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
