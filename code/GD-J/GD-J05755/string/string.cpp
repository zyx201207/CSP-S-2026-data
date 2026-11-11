#include<bits/stdc++.h>
using namespace std;
long long n;
stack<char> st1,st2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long num=0;
	cin>>n;
	for(long long i=1,x;i<=n;i++){
		char c;
		cin>>x>>c;
		num+=x;
		for(long long j=1;j<=x;j++){
			st1.push(c);
		}
	}
	for(long long i=1;i<=num/2;i++){
		char c=st1.top();
		st2.push(c);
		st1.pop();
	}
	st1.pop();
	long long ans=0;
	for(long long i=1;i<=num/2;i++){
		if(st1.top()!=st2.top()) ans++;
		st1.pop();
		st2.pop();
	}
	cout<<ans;	
	return 0;
}
