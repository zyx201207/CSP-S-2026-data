#include <bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
deque<long long> s;
int main(){
	freopen("string.in","r",stdin);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s.push_back(y);
		}
	}
	while(!s.empty()){
		long long r=s.back();
		s.pop_back();
		if(s.empty())break;
		long long l=s.front();
		s.pop_front();
		if(l!=r)ans++;
	}
	freopen("string.out","w",stdout);
	cout<<ans;
	return 0;
}
