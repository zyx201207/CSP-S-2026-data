#include<bits/stdc++.h>

using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,a;
	string sum;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a>>sum;
		long long j=0;
		for(;j<=a-1;j++){
			s+=sum;
		}
		ans+=a;
	}
	long long l=0,r=ans-1,k=0;
	while(l<=r){
		if(s[l]!=s[r]){
			k++;
		}
		l++;
		r--;
	}
	cout<<k;
	return 0;
}


