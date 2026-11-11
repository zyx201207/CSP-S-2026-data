#include<bits/stdc++.h>
using namespace std;
long long n,l=0,mid,cnt=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		while(a--){
			s+=c;
		}
	}

	if(l%2==0)mid=l/2;
	else mid=(l-1)/2;
	for(long long i=0;i<=mid-1;i++){
		if(s[i]!=s[l-i-1]){
			cnt++;

		}
	}
	cout<<cnt;
	return 0;
}
