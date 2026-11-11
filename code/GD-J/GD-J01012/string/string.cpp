#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s,sum;
long long a[N];
int n;
long long ans,z;
//long long l=1,r,x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	sum+='#';
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		z+=a[i];
		for(int j=1;j<=a[i];j++){
			sum+=s[i];
		}
	}
	/*
	r=n;
	x=a[1];
	while(l<=n/2){
		if(x<a[r]){
			if(s[l]!=s[r])ans+=x;
			x=a[r]-x;
		}
		else if(x>)
	}
	*/
	for(long long l=1;l<=z/2;l++){
		long long r=z-l+1;
		if(sum[l]!=sum[r]){
			ans++;
		}
	}
	cout<<ans;
	/*
	for(long long l=1;l<=(n+1)/2;l++){
		long long r=n-l+1;
		long long p=min(a[l],a[r]);
		x=max(a[l],a[r])-p;
		if(s[l]!=s[r]){
			ans+=p;
		}	
	}*/
	return 0;
}


/*

6 
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
