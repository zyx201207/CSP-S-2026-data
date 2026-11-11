#include<bits/stdc++.h>
using namespace std;
long long n,num,ans;
char s[9999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long st=0;
	for(long long i=1;i<=n;i++){
		long long g;
		char z;
		cin>>g>>z;
		num+=g;
		for(long long j=1;j<=g;j++){
			s[st+j]=z;
		}
		st=st+g;
	}
	for(long long i=1,j=num;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
