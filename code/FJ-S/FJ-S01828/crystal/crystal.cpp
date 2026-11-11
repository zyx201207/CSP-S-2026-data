#include<bits/stdc++.h> 
using namespace std;
long long n=0,m=0,ans=1,ans1=0,b=0,m1=0,x=0;
bool q=1,p=1; 
long long a[600000]={},a1[600000]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(i>0){
			if(a[i]!=a[i-1]){
				q=0;
			}
		}
		a1[i]=a[i];
	}
	if(q){
		if(m%n==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<n-1;
			return 0;
		}
	}
	sort(a,a+n);
	for(long long i=0;i<n-1;i++){
		x+=a[n-1]-a[i];
	}
	if(m>=x){
		if((m-x)%n==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<n-1;
			return 0;
		}
	}
	sort(a1,a1+n);
	for(long long i=a[0]+1;i<a[n-1]+m/2+1;i++){
		for(long long j=0;j<n;j++){
			if(a[j]<=i){
				a1[j]=i-a[j];
				b=j;
			}
			else{
				a1[j]=0;
			}
			
		}
		while(m1>=0&&b>=0){
			m1=m1-a1[b];
			ans1++;
			if(m1<0){
				ans1--;
			}
			b--;
		}
		ans=max(ans,ans1);
		m1=m;
		ans1=0;
		b=0;
		for(long long j=0;j<n;j++){
			a1[j]=a[j];
		}
	}
	cout<<ans;
}
