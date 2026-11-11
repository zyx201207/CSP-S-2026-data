#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],maxx,ans;
char c[200005],cc[200000000000005];
int main(){
	cin>>n;
	freopen("string.in","r",stdin);
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=0;j<a[i];j++){
			cc[maxx+j] = c[i];
		}
		maxx += a[i];
	}
	if(n%2==0){
		for(long long i=0;i<n/2;i++){
			if(cc[n/2-i-1]!=cc[n/2+i]) ans++;
		}
	}
	else{
		for(long long i=0;i<n/2;i++){
			if(cc[n/2-i]!=cc[n/2+i]) ans++;
		}
	}
	cout<<ans;
	freopen("string.out","w",stdout);
	return 0;
}
