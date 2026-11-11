#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char c;
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l=l+a;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	long long i=0,j=l-1,cnt=0;
	for(;i<=j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
