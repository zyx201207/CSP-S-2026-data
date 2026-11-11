#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
ll C,T,n,d,a[N];map<ll,ll>mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(ll i=1;i<=n;i++)scanf("%lld",a+i);
		if(n<=2){printf("0\n");continue;}
		ll dlt=a[2]-a[1],tmp=0,num=0;
		while(tmp<=d){tmp+=dlt,num++;}
		if(num<3){printf("0\n");continue;}
		printf("%lld",n-num);
	}
	return 0;
}
//30min EXP: 8pts
/*
 * A:
 * notice:
 * a1  <--T=3-->  a2   <--T=3-->  a3  <--...-->  an
 * let dlt means the smallest distance it can't acheive once
 * so everytimes, dlt+=T
 * when dlt>d 
 * then we have :
 * a1  <--T=3-->  a2  <--...--> a1+dlt  ,let a1+dlt=at . it's easy to testify that t<=n
 * so there're 2 ways to acheive the a_t:
 * 
 * a1->a_t-1->aT
 *and a1->a2->at
 * 
 * therefore the answer is: n-t+1
 * 
 * we can get 8pts
 */
