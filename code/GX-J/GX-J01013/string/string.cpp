#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[2005];
	cin>>n;
	string b="";
	long long ans=0;
	char c[2005];
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(c[i]!=' '){
			cin>>c[i];
		}
		ans+=a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			b+=c[i];
		}
	}
	long long cnt=0,sum=ans-1;
	if(n==1){
		cout<<"0";
		return 0;
	}
	else{
		for(long long i=0;i<=ans/2-1;i++){
			if(b[i]!=b[i+sum]){
				cnt++;
			}
			sum-=2;
		}
	}
	cout<<cnt;
	return 0;
}
