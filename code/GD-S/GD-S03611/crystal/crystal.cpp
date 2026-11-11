#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],maxxx=0;
bool f=1,ff=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
		if(!(a[i]-a[i-1]==a[i-1]-a[i-2]&&i>=3))ff=0;
	}
	if(ff){
		double e=sqrt(2/(a[2]-a[1])*m+0.25)+0.5;
		cout<<min((long long)e,n);
		return 0;
	} 
	if(f){
		double e=sqrt(2*m+0.25)+0.5;
		cout<<min((long long)e,n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long maxx=a[i],sum=0,summ=0,h;
		for(int j=i;j<=n;j++){
			if(a[j]<=maxx){
				sum+=maxx-a[j];
			}else{
				sum+=(abs(a[j]-maxx))*(j-i);
				maxx=a[j];
			}
			if(sum>m)break;
			h=j-i+1;
			summ=sum;
		}
		maxxx=max(maxxx,h);
	}
	cout<<maxxx;
	return 0;
}
