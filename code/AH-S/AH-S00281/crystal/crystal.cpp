#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],x[500010],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		x[i]=a[i]-a[i-1];
	}
	long long sm=1;
	for(long long i=2;i<=n;i++){
		sum=x[i]*(i-1);
		m-=sum;
		if(m>=0){
			sm=i;
		}
		else{
			cout<<sm;
			return 0;
		}
	}
	return 0;
}
