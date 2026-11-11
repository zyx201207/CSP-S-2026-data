#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx,maxx2,maxx3,ans;
long long a[200005];
long long s[200005];
long long r[200005];
int dfs(long long k,long long x){
	if(k>m){
		if(x>maxx3) {
		   maxx3=x;
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		if(r[i]==0){
			if(k==1){
			r[i]=1;
			dfs(k+1,a[i]);
			r[i]=0;
		    }
		else {
			r[i]=1;
			dfs(k+1,(x&a[i]));
			r[i]=0;
		     }	
	}
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	s[1]=a[1];
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++) {
		cin>>a[i];
		if(a[i]>maxx) maxx=a[i];
		s[i]=(a[i]&s[i-1]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<s[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>maxx2) maxx2=a[i]&a[j];
			}
		}
		cout<<maxx2;
		return 0;
	}
	if(m==n-1){
		long long p;
		for(int i=1;i<=n;i++){
			if(i==1) p=a[2];
			else p=a[1];
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				p=p&a[j];
			}
		}
		cout<<p;
		return 0;
	}
	dfs(1,1);
	cout<<maxx3;
	return 0;
}
