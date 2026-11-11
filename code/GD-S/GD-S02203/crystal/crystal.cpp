#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
long long int n,m,a[N];
int A,B;
long long int fun(int x){
	long long int cnt=m,sum=0;
	for(int i=x-1;i>=1;i--){
		cnt-=(a[x]-a[i]);
		if(cnt>=0)sum++;
		else break;
	}return sum+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)A=1;
		if(i>=3&&((a[i]-a[i-1])!=(a[i-1]-a[i-2])))B=1;
	}
	if(A==0){
		long long int i=0;
		while(m>=0){
			i++;
			m-=i;
		}cout<<i;
		return 0;
	}
	if(B==0){
		m=m/(a[2]-a[1])-1;
		long long int sum=0,i=1;
		while(m>=0){
			sum++;
			i++;
			m-=i;
		}cout<<sum+1;
		return 0;
	}sort(a+1,a+n+1);
	long long int ma=0;
	for(int i=n;i>=1;i--){
		ma=max(ma,fun(i));
	}
	cout<<ma;
	return 0;
}
