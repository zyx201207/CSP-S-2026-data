#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,cnt;
long long a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=a[i];j>=1;j--){
			s+=c[i];
		}
	}
	for(long long i=0;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i-1]) cnt++;
	}
	cout<<cnt;
	return 0;
}
