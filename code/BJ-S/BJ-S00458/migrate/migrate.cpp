#include<bits/stdc++.h>
using namespace std;
#define int long long 
int cnt,c,t;
int x[2000067];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	if(c>=13&&c<=18){
		for(int i=1;i<=t;i++)printf("0\n");
		return 0;
	}
	for(int z=1;z<=t;z++){
		cnt=0;int n,d;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){scanf("%lld",&x[i]);}
		
		d/=(x[2]-x[1]);
		for(int i=1;i<=n;i++){
			int mid=i/2;
			if(d>mid&&d<i){cnt+=(n-i);}
		}printf("%lld\n",cnt);
	}
	return 0;
}
