#include<bits/stdc++.h>
using namespace std;
char a[200050];
long long q[200050],b[200050],c[200050];
long long n,ans,s,t;
int main(){
	cin>>n;
	ans=0;
	b[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>q[i];
		cin>>a[i];
		b[i]=q[i]+b[i-1];
	}
	c[n+1]=0;
	for(long long i=n;i>=1;i--){
		c[i]=q[i]+c[i+1];
	}
	if(b[n]<=300050){
		char c[300050];
		for(long long i=1;i<=n;i++){
			for(long long j=b[i-1]+1;j<=b[i];j++){
				c[j]=a[i];
			}
		}
		for(long long i=1;i<=b[n];i++){
			//cout<<c[i]<<" "<<c[n-i+1]<<" ";
			if(c[i]!=c[n-i+1]) ans++;
		}
		ans=ans/2;
	}else{
		s=1;
		t=n;
		while(s!=t){
			if(b[s]>=c[t]){
				if(b[s-1]<=c[t+1]){
					if(a[t]!=a[s]) ans+=q[t];
					t--;
				}else{
					if(a[t]!=a[s]) ans+=c[t]-b[s-1];
					if(a[t]!=a[s-1]) ans+=b[s-1]-c[t+1];
				}
			}else s++;
		}
		if(b[s]>=c[s]){
			if(b[s-1]>c[s+1]){
				if(a[t]!=a[s-1]) ans+=b[s-1]-c[t+1]; 
			}
		}
		
	}
	cout<<ans;
	return 0;
} 
