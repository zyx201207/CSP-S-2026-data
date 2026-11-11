#include<bits/stdc++.h>
using namespace std;
string s="",c;
long long n,a,cnt=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>a>>c;
	for(int j=1;j<=a;j++){
			s+=c;
	}
	long long a1=a;
	string c1=c;
	for(int i=2;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			cnt++;
		}
	}
	if(a==a1&&c==c1) cnt--;
	cout<<cnt;

	
	
}
