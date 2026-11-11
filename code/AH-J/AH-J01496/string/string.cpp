#include<bits/stdc++.h>
using namespace std;
char a[1000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=1,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long q;
		char w;
		cin>>q>>w;
		for(long long j=1;j<=q;j++){
			a[s]=w;
			s++;
		}
	}
	int sign=0;
	if(s%2==1){
		s=s-1;
		sign=1;
	}
	for(long long i=s/2;i<=s-sign;i++){
		if(a[i]!=a[s-sign-i]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
