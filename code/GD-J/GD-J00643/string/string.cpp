#include<bits/stdc++.h>
using namespace std;
long long b[1010000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long x=1;
	long long s=0;
	long long ans=0;
	while(n--){
		long long a;
		cin>>a;
		s+=a;
		char c;
		cin>>c;
		while(a--){
			b[x]=c;
			x++;
		}
	}
	for(long long i=1;i<=s/2;i++){
		if(b[i]!=b[s-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
