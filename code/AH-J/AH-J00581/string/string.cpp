#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long f=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		if(a>=1000000000){
			f=1;
			continue;
		}
		for(int j=0;j<a;j++){
			s.push_back(c);
		}
	}
	if(f==1){
		cout<<l/2;
		return 0;
	}
	long long mid=l/2,cnt=0;
	for(int i=mid;i<l;i++){
		if(s[i]!=s[l-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
