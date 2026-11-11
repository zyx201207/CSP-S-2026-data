#include<bits/stdc++.h>
using namespace std;
struct node {
	int x1;
	char x2;
};

long long ans=0;
bool check(string k,string l) {
	for(int i=0; i<k.size(); i++)
		if(k[i]!=l[i])
			return false;
	return true;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1) {
		cout<<0;
		return 0;
	}
	string s,s1;
	node b[200005];
	for(int i=0; i<n; i++)
		cin>>b[i].x1>>b[i].x2;
	for(int i=0; i<n; i++)
		for(long long j=0; j<b[i].x1; j++)
			s+=b[i].x2;
	for(long long i=1; i<=s.size(); i++)
		s1+=s[s.size()-i];
	if(check(s1,s)==true) {
		cout<<0;
		return 0;
	}
	if(s.size()%2==0) {
		int xx=s.size()/2;
		for(long long i=0; i<xx; i++)
			if(s[i]!=s1[i])
				ans++;
	} else {
		int xx=(s.size()-1)/2;
		for(long long i=0; i<xx; i++)
			if(s[i]!=s1[i])
				ans++;
	}
	cout<<ans;
	return 0;
}
