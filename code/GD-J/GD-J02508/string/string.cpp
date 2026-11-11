#include<bits/stdc++.h>
using namespace std;
long long n,z,q,s;
long long a[200010];
char x[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		cin >> x[i];
		if(x[i]!=x[i-1]&&i-1!=0){
			q=1;
		} 
		z+=a[i];
		z%=2;
		s=ceil(1.0*(s+a[i])/2);
	}
	if(q==0){
		cout << 0;
		return 0;
	}
	if(z==1){
		for(long long i=1;i<=s;i++){
			if(x[i]!=x[n-i+1]){
				if(i-1==n-i+1){
					break;
				}
				ans+=min(a[i],a[n-i]); 
				a[i]-=ans;
				a[n-i]-=ans;
				
			} 
		}
	}
	else{
		for(long long i=1;i<=s;i++){
			if(x[i]!=x[n-i+1]){
				if(i-1==n-i+1){
					break;
				}
				ans+=min(a[i],a[n-i]); 
				a[i]-=ans;
				a[n-i]-=ans;
				
			} 
		}
	} 
	cout << ans;
	return 0;
}
