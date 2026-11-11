#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	long long t=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=t;j<t+a;j++){
			s[j]=c;
		}
		t+=a;
	}
	long long l=0,r=t-1;
	while(l<=r){
		if(s[l]!=s[r])sum++;
		l++,r--;
	}
	cout<<sum;
	return 0;
}
