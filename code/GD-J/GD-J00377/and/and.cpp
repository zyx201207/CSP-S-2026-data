#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
using ll=long long;
ll N,M;
ll Arr[100001];
int Cnt1(ll N){
	int Sum=0;
	ll Tmp=N;
	while(Tmp){
		Sum+=(Tmp&1);
		Tmp>>=1;
	}
	return Sum;
}
bool Cmp(ll A,ll B){
	if((Cnt1(A)>Cnt1(B))&&A>B)return 1;
	else return A>B;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int I=1;I<=N;I++){
		scanf("%lld",&Arr[I]);
	}
	sort(Arr+1,Arr+N+1,Cmp);
	ll Ans=Arr[1];
	for(int I=1;I<=M;I++){
		Ans&=Arr[I];
	}
	printf("%lld",Ans);
	return 0;
}

