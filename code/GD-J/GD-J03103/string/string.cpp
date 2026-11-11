#include <bits/stdc++.h>
using namespace std;
int n,len,cnt;
string s;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		if(a>=1e5){
			f=1;
		}
		len+=a;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
	}
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	if(cnt==0&&f==1){
		cout<<n/2;
	}else{
		cout<<cnt;
	}
	return 0;
}
