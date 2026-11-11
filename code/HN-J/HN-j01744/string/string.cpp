#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long t,l=a.size();
		char c;
		cin>>t>>c;
		for(long long i=1;i<=t;i++) a+=c;
		for(long long i=0;i<l/2;i++){
			if(a[i]!=a[l-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
