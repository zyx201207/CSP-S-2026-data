#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int maxn=2e5+5;
int slen[maxn];
char scon[maxn];
int n;
string s;
long long ans=0;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>slen[i]>>scon[i];
	}
	for(int i=1;i<=n;i++){
		int m=slen[i];
		while(m--){
			s+=scon[i];
		}
	}
	int l=0;
	int r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}


