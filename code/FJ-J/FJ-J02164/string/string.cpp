#include<bits/stdc++.h>
using namespace std;
//unsigned const struct  (vector pueue stack ) push pop empty / pow abs sqrt /reverse unqine
//scanf printf %.3f %lf %d
//fixed setpreicion
long long a[10005];
long long c[10005];
char b[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n; 
	long long l = 0;
	for(long long i =1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i] = c[i-1]+a[i];
		l+=a[i];
	}
	long long p = 1;
	long long ans =0; 
	for(long long i =l;i>=(l%2==1?((l+1)/2):(l/2));i--){
		long long o = n;
		while(o>0){
			if(c[o-1]<i&&c[o]>=i){
				break;
			}else{
				o--;
			}
		}
		long long k = 1;
		while(k<=n){
			if(c[k-1]<(l-i+1)&&c[k]>=(l-i+1)){
				break;
			}else{
				k++;
			}
		}
		if(b[o]!=b[k]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
