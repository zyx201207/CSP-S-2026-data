#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[200005];
	char b[200005];
	string s;
	long long n;
	cin>>n;
	long long l=0,p=1,sum=0;
	for(long long i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(long long i=1;i<=n;i++)l+=a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s[p]=b[i];
			p++;
		}
	}
	for(int i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[l+1-i])sum++;
	}
	cout<<sum;
	return 0;
}

