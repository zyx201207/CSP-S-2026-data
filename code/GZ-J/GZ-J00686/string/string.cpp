//GZ-J00686遵义市第十二中学刘彦城
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	string qb;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s+=b;
		}
	}
	long long len;
	if((s.size())%2==0) len=(s.size())/2;
	else len=(s.size()-1)/2;
	for(long long i=0;i<=len-1;i++){
		qb+=s[i];
	}
	long long cnt=0;
	long long j=s.size()-1;
	for(long long i=0;i<=len-1;i++){
		if(qb[i]!=s[j]) cnt++;
		j--;
	}
	cout<<cnt;
	return 0;
}

