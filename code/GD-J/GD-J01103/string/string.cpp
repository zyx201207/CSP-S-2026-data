#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,s;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>b[i];
	}
	for(int i=1;i<=(n+1)/2-1;i++){
		if(a[i]==a[n-i+1]) {
			if(b[i]!=b[n-i+1])	s+=a[i];
		} 
		if(a[i]<a[n-i+1]) {
			for(int j=1;j<=n;j++){
				if(a[i+1]>=a[n-i+1]-a[i]) {
				if(b[i+1]==b[n-i+1]) a[i+1]=a[i+1]-(a[n-i+1]-a[i]);
				else {
					a[i+1]=a[i+1]-(a[n-i+1]-a[i]);
					if(a[i]==a[n-i+1])
						s+=abs(a[n-i+1]-a[i]);
					else
						s+=max(a[n-i+1],a[i]);
				}
			}
			}	
		}
		if(a[i]>a[n-i+1]) {
			if(a[n-i+1-1]>=a[i]-a[n-i+1]) {
				if(b[i+1]==b[n-i+1]) a[n+1]=a[n+1]-(a[i]-a[n-i+1]);
				else {
					a[n-i]=a[n-i]-abs(a[n-i+1]-a[i]);
					if(a[i]==a[n-i+1])
						s+=abs(a[n-i+1]-a[i]);
					else
						s+=max(a[n-i+1],a[i]);
				}
			}	
		}
	}
	if(n%2==0){
		if(b[n/2]==b[n/2+1]) {
			s+=0;
		}
		else if(a[n/2]==a[n/2+1]) {
			if(b[n/2]!=b[n/2+1])	s+=a[n/2];
		} 
		else {
			long long x=a[n/2]+a[n/2+1];
			if(x%2==0) s+=abs(x/2-a[n/2]);
			else s+=min(a[n/2],a[n/2+1]);
		}
	}
	printf("%lld",s);
	return 0;
}

