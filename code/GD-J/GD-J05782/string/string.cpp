#include<bits/stdc++.h>
using namespace std;
long long n;
long long s;
char a;
long long p=1;            
long long sum=0;
long long t;
char q[911111111];
int main(){
	 freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
cin>>n;
	for(long long i=1;i<=n;i++){
	cin>>s>>a;
	sum+=s;
	for(long long j=1;j<=s;j++){
		q[p++]=a;
	}
	}
	for(long long i=1;i<=sum/2;i++){
	if(q[i]!=q[sum+1-i]) t++;
		
	}
	cout<<t;
	return 0;
}
