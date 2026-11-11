#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,f,sum;
	cin>>n;
	string s;
	string s1,s2;
	for(long long i=1;i<=n;i++){
		cin>>f;
		cin>>s1;
		sum+=f;
		for(long long j=1;j<=f;j++) {
			s+=s1;
		}
	}
	long long cnt=0;
	long long l=sum-1;
	for(long long i=0;i<=sum/2+1;i++){
		if(s[i]!=s[l]){
			s[l]=s[i];
			cnt++;
			l--;
		}
		else l--;
	}
	cout<<cnt;
	return 0;
}
