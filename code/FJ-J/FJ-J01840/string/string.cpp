#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,s=1,d;
	cin>>n;
	long long a[n],ans=0;
	char c[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		t+=a[i];
	}
	char str[t+1];
	for(long long i=0;i<t;i++){
		for(long long j=0;j<a[i];j++){
			str[s++]=c[i];
		}
	}
	d=t-1;
	for(long long i=1;i<=(t+1)/2;i++){
		if(str[i]!=str[d-i]){
			ans++;
		}	
	}
	cout<<ans;  
	return 0;
}
