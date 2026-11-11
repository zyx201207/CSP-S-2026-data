#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	reopen("string.in","r",stdin);
	reopen("string.out","w",stdout);
	vector <int> a;
	long long sum=0;
	a.push_back(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		sum+=x;
		char temp;
		cin>>x>>temp;
		int b=temp-'a';
		for(long long j=1;j<=x;j++){
			a.push_back(b);
		}
	}
	long long ans=0;
	for(long long i=1;i<=(sum/2);i++){
		if(a[i]!=a[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}