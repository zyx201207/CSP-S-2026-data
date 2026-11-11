#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		long long x;
		cin>>x;
		char a;
		cin>>a;
		for(int j = 0;j<x;j++){
			s+=a;
		}
	}
	long long sum = 0,si = s.size();
	for(int i = 0;i<(si+1)/2;i++){
		if(s[i]!=s[si-1-i])sum++;
	}
	cout<<sum;
	return 0;
}

