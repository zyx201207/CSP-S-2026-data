#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;  
string s; 
long long n,len=0,ans; 
int g[N][3]; 
stack<int> a1;
queue<int> a2;  
int main() {
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	cin>>n; 
	for(int i=1;i<=n;i++) {
		int x; 
		char c; 
		cin>>x>>c; 
		for(long long i=1;i<=x;i++) s+=c; 
		len+=x; 
	}
	long long mid=len/2,l=0,r=len-1; 
	while(true) {
		if(l>=r) break; 
		if(s[l]!=s[r]) ans++; 
		l++,r--; 
	} 
	cout<<ans; 
	
	return 0; 
}
