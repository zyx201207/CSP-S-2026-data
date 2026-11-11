#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		cin>>a;
		char ch;
		cin>>ch;
		for(long long j=1;j<=a;j++){
			s+=ch; 
		}
	}
	long long len=s.size();
	long long lf=0,rt=len-1;
	while(lf<rt){
		if(s[lf]!=s[rt]){
			cnt++;
		}
		lf++;
		rt--;
	}
	cout<<cnt;
	return 0;
}

