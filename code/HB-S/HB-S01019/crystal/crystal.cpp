#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long a[N];
long long sum,n,m,l;
bool cmp(long long  x,long long y){
		return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(n%2==0){
		l=n/2;
	}else{
		l=((n+1)/2)-1;
	}
	long long maxn=a[l];
	for(long long i=l-1;i>=0;i--){
		long long j=maxn-a[i];
		if(m>=j){
			m-=j;
			while(j--){
				a[i]++;
			}
		}
	}
	for(long long i=n-1;i>=0;i--){
		if(a[i]==maxn){
			sum++;
		}     
	}
	cout<<sum;
	return 0;
}
