#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string S;
	long n,cnt=0,l=0,sum=0;
	cin>>n;
	for(long i=1;i<=n;i++){
		long a;
		char c;
		cin>>a>>c;
		l+=a; 
		for(long j=1;j<=a;j++){
			cnt++; 
			S[cnt]=c;
		}
		
	}
	for(long i=1;i<=l/2;i++){
		if(S[i]!=S[l+1-i]) sum++;
	}
	cout<<sum;
	return 0;
} 
