#include<bits/stdc++.h>
using namespace std;
long long n,maxn=-0x3f3f3f3f,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;char c;
		cin>>x>>c;
		maxn=max(maxn,x);
		for(int i=0;i<x;i++){
			s+=c;
		}
	}
	long long l=0,r=s.length()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}

