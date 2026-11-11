//田缮恺 GZ-S00381 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0,minn=1e8,sp,spi,sm,sum,sd,sc;
long long a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			s+=a[j]-a[i];
		}
		sd+=s;
		if(minn>=abs(s)){
			minn=abs(s);
			sp=a[i];
			spi=i;
		}
		s=0;
	}
	if(sd==0){
		sc=abs(a[0]-a[1]);
		for(long long i=1;i<=n;i++){
			sm+=sc*i;
			if(sm>m){
				sum=i;
				break;
			}
		}
	}else{
		for(long long i=spi-1;i>=0;i--){
			if(m==0){
				break;
			}
			sm=a[spi]-a[i];
			m-=sm;
			a[i]+=sm;
		}
		for(long long i=0;i<n;i++){
			if(a[i]==a[spi]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}  
