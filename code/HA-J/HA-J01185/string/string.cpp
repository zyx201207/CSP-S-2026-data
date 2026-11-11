#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll D=10e9+5;
int n,cnt=0;
vector<int> x(D,0);
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	while(n--) {
		ll cn=0;
		string s1;
		cin>>x[cn]>>s1;
		for(int i=0; i<x[cn]; i++) {
			s+=s1;
		}
	}
	ll len=s.size();
	if(n!=1) {
		for(int i=0,j=len; i<len/2,j>len/2; i++,j--) {
			char si=s[i];
			char sj=s[j];
			if(si!=sj) {
				cnt++;
			}
		}
	} else {
		cout<<0;
		return 0;
	}
	cout<<cnt;
	return 0;
}
