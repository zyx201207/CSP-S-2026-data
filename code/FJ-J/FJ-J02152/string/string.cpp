#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int a[N];
char b[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	long long cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			s+=b[i];
		}
		cnt+=a[i];
	}
	int ct=0;
	for(int i=0; i<cnt/2; i++) {
		if(s[i]!=s[cnt-i-1]) {
			ct++;
		}
	}
	cout<<ct;

	return 0;
}
