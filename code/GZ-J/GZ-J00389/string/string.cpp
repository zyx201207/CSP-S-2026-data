#include<bits/stdc++.h>
using namespace std;
int s[100000000];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long j=1,sum=0;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		sum+=x;
		char c;
		cin>>c;
		for(;j<=sum;j++) s[j]=c;
	}
	if(sum%2) j=2;
	else j=1;
	sum/=2;
	long long cnt=0;
	while(sum!=0){
		if(s[sum]!=s[sum+j]) cnt++;
		j+=2;
		sum--;
	}
	cout<<cnt;
	return 0;
}
