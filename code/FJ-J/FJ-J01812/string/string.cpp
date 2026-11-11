#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	//wudiaofkfd
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans=0,len=s.size();
	for(long long i=len/2;i<len;i++){
		if(s[i]!=s[len-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
