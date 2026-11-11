#include<iostream>
#include<cstdio>
#include<algorithm>

#define int long long

using namespace std;

const int M=5e5+5;

int a[M];



signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	scanf("%lld%lld",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	sort(a+1,a+n+1);
	
	int ans=0;
	
	int now=a[1],sum=1,res=0;
	
	int l=1;
	
	for(int i=2;i<=n;i++){
		int det=a[i]-now;
		res+=det*sum;
		now=a[i];
		sum++;
		if(res>m){
			for(int j=l;j<i;j++){
				res-=(now-a[j]);
				sum--;
				l++;
				if(res<=m)break;
			}
		}
		ans=max(ans,sum);
	}
	
	printf("%lld",ans);
	
	return 0;	
}


/*
5 5 
1 2 4 8 9


5 8
-3 -1 2 2 7


*/


