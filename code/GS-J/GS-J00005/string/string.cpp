#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> s;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(long long i=0;i<a;i++){
			s.push_back(c);
		}
	}
	long long l=0,r=s.size()-1;
	long long cnt=0;
	while(r-l>1){
		if(s[r]!=s[l]) cnt++;
		r--;
		l++;
	}
	cout<<cnt;
	return 0;
}
