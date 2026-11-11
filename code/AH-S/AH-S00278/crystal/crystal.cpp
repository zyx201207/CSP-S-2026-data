#include<bits/stdc++.h>
using namespace std;
int N;
long long M,A[500010];
long long B[500010],C[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%lld",&A[i]);
	sort(A+1,A+1+N);
	for(int i=1;i<=N-1;i++){
		C[i]=A[i+1]-A[i];
		B[i]=A[i+1]-A[i];
		C[i]+=C[i-1];
	}
	int ans=1,res=1,lastid=0;
	long long sum=0;
	for(int i=1;i<=N-1;i++){
		sum+=B[i]*(i-lastid);
		res++;
		while(sum>M){
			sum-=C[i]-C[lastid];
			lastid++;
			res--;
		}
		ans=max(ans,res);
	}
	printf("%d",ans);
	return 0;
}
