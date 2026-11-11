#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100005];
char c[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long ans=0;
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//±©Á¦ 
