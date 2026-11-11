#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flagA=1,flagB=1;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flagA=0;
		}
		if(i>2){
			if((a[i]-a[i-1])!=(a[2]-a[1])){
				flagB=0;
			}
		}
	}
	if(flagA){
		double x=2*m+0.25;
		x=sqrt(x);
		x-=0.5;
		unsigned long long o=x;
		o++;
		cout<<min(n,o);
	}else if(flagB){
		unsigned long long k=abs(a[2]-a[1]);
		double x=2*m/k+0.25;
		x=sqrt(x);
		x-=0.5;
		unsigned long long o=x;
		o++;
		cout<<min(n,o);
	}else{
		sort(a+1,a+n+1);
		a[n+1]=LLONG_MAX;
		long long jizhuen;
		unsigned long long ans=0; 
		for(unsigned long long i=n;i>=1;i--){
			if(a[i]== a[i+1])continue;
			jizhuen=a[i];
			unsigned long long num=0;
			int Nowm=m;
			for(unsigned long long j=i;j>=1;j--){
				if(Nowm>=jizhuen-a[j]){
					num++;
					Nowm-=jizhuen-a[j];
				}else{
					break;
				}
			}
			ans=max(ans,num);
		} 
		cout<<ans;
	}
		
	return 0;
}
