#include<bits/stdc++.h> 
using namespace std;
const long long N=7e5;
long long a[N],n,m,ans=1;
long long c(long long x,long long y){
	long long sum=1;
	for(long long i=x-1;i>=1;i--){
		long long s=abs(a[x]-a[i]);
		if(s<=y){
			y-=s;
			sum++;
		}
		else{
			return sum;
		}
	}
	return sum;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=6000){
		for(long long i=n;i>=1;i--){
			ans=max(ans,c(i,m));
		}
		cout<<ans;
	}
	else{
		long long df=a[2]-a[1],x=1;
		df=m/df;
		for(int i=1;i<=m;i++){
			if(m-i>0){
				m-=i;
				x++;
			}else{
				break;
			}
		}
		cout<<x;
	}
	return 0;
}
