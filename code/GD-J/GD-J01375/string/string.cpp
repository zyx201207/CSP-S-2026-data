#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n;
long long len,ans;
long long ton[N];
long long a[N];
char c[N];
int main(){
	freopen("string5.in","r",stdin);
	freopen("string5.out","w",stdout);
	cin>>n;
	 
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		ton[i]=ton[i-1]+a[i];
	}
	
	if(len%2==1) len-=1;
	len/=2;
	long long i_last;
	for(long long i=1;i<=n;i++){
		i_last=i;
		if(ton[i]>len) break;
	}
	
	long long i=1,half=i_last;
	if(ton[i_last-1]<n and (n%2==0 or a[i_last]==1)){
		for(int i=0;i<=i_last;i++){
			a[i]=a[i+1];
			c[i]=c[i+1];
		}
		a[i_last-1]=len-a[i_last-2];
		a[i_last]=len-a[i_last-1];
		if(n/2!=0){
			a[i_last]-=1;
		}
		i-=1;
		n+=1;
	}else if(n%2==0 and  a[i_last]==1) i_last++;
	
	while(i+i_last-half<n){
		if(c[i]!=c[i_last]) {
			ans+=min(a[i],a[i_last]);
			
		}
		if(a[i]<a[i_last]){
			a[i_last]-=a[i];
			i++;
		} else if(a[i]==a[i_last]){
			i++;
			i_last++;
		}
		else{
			a[i]-=a[i_last];
			i_last++;
		}
	}
	cout<<ans;
	return 0;
}

