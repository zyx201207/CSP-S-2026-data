#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long cnt=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++) s+=c;
	}
	for(long long l=0;l<=s.length()/2-1;l++){
		long long r=s.length()-1-l;
			if(s[l]!=s[r]) cnt+=1;
	}
	cout<<cnt;
	return 0;
}
