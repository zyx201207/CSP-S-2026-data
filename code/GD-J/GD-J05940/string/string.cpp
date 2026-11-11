#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long n,cnt=0;
long long a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
