#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string c;
		cin>>x>>c;
		for(long long i=1;i<=x;i++){
			s+=c;
		}
	}
	long long cnt=0;
	string t=s;
	reverse(s.begin(),s.end());
	for(size_t i=0;i<s.size();i++){
		if(t[i]!=s[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}
