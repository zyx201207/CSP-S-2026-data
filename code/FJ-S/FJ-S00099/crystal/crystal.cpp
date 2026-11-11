#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=5e5+5;

int n;
ll m,a[MAXN],s[MAXN]; 

bool check2(int x,ll c){
	int L=0,R=n+1;
	while(L+1<R){
		int M=(L+R)>>1;
		if(a[M]<=c){
			L=M;
		}else{
			R=M;
		}
	}
	if(L<x){
		return 0;
	}else{
		ll num=1LL*c*x-(s[L]-s[L-x]);
//													if(x==315186&&c==a[315187]){
//																	printf("%lld\n",num);
//													}
//													printf("%d,%lld:%lld\n",x,c,num);
		if(num>m){
			return 0;
		}else{
			return 1;
		}
	}
}

bool check1(int x){
	ll L=x,R=n+1;
	bool flag=0;
	while(L+1<R){
		ll M=(L+R)>>1;
		if(check2(x,a[M])){
			L=M;
			flag=1;
		}else{
			R=M;
		}
	}
	return flag;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int L=1,R=n+1;
	while(L+1<R){
		int M=(L+R)>>1;
		if(check1(M)){
			L=M;
		}else{
			R=M;
		}
						//	printf("%d-%d\n",L,R);
	}
	printf("%d",L);
	return 0;
}
