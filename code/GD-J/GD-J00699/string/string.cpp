#include<bits/stdc++.h>
#include<string>
using namespace std;
long long l,ad,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(long long i=0;i<l;i++){
		long long a;
		cin>>a;
		char word;
		cin>>word;
		for(long long j=0;j<a;j++){
			s[ad]=word;
			ad++;
		}
	}
	long long mid=ad/2;
	for(long long i=0;i<mid;i++){
		if(s[i]!=s[ad-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
