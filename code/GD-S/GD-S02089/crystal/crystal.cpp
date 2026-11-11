#include<iostream>
#include<algorithm>

using namespace std;

long long a[500010];
long long n; 
long long m;
long long turn(long long x,long long xi){
	long long sum=0,an=0;
	for(long long j=xi-1;j>=0;j--){
		if(sum>m){
			return an;
		}
		if((x-a[j])<0) return an;
		sum+=(x-a[j]);
		an++;
		//°Ñx±äÎªa[i] 
	}
	return an;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(long long i=n;i>=1;i--){
		ans=max(ans,turn(a[i],i));
	} 
	cout<<ans;
	return 0;
} 
