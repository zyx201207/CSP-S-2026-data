#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,mina=1000000000;
	string ans;
	cin >> n;
	for(long long i=1;i<=n;i++){
		long long a;
		cin >> a;
		if(a<mina)  mina=a;
		char s;
		cin >> s;
		for(long long j=sum;j<a+sum;j++)
			ans+=s;
		sum+=a;
	}
	if(n==1)
		cout << 0;
	else if(n==2)
		cout << mina;
	return 0;
}
