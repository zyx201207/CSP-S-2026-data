#include<bits/stdc++.h>
using namespace std;

string S;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i = 1;i <= n;i++){
		long long m;
		string s;
		cin>>m>>s;
		for(long long j = 1;j <= m;j++){
			S += s; 
		}
	}
	long long l = S.length();
	long long ans = 0;
	for(long long i = 0,j = l - 1;i < l,j >= 0;i++,j--){
		if(S[i] != S[j]) ans++;
	}
	cout<<ans / 2;
	return 0;
}
