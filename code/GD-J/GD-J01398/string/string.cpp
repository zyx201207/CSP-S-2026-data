#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long n;
	string a;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long p=0;
		string an;
		cin>>p>>an;
		for(long long j=1;j<=p;j++){
			a+=an;
		}
	}
	long long l=a.size(),ans=0;
	for(long long i=0;i<a.size()/2+1;i++){
		if(a[i]!=a[l-1-i]){
			ans++;
			a[l-1-i]=a[i];
		}
	}
	cout<<ans;
	return 0;
} 

