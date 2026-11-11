#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ch=0;
	string s="";
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		ch+=a;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	string s1=s;
	long long z=0;
	reverse(s1.begin(),s1.end());
	for(long long i=0;i<ch;i++){
		if(s[i]!=s1[i]) z++;
	}
	cout<<z/2;
	return 0;
}

