#include<bits/stdc++.h>
using namespace std;
long long n,a[2*100000+5],ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s=s+c;
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
		ans++;
	}
	cout<<ans;
	return 0;
} 
