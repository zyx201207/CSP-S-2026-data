#include <bits/stdc++.h>
using namespace std;
long long n,num,wzt;
long long a;
char w;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=' ';
	for(long long i=1;i<=n;i++){
		cin>>a>>w;
		num+=a;
		for(long long j=1;j<=a;j++){
			s+=w;
		}
	}
	for(long long i=1,j=num;i<=num/2,j>num/2;i++,j--){
		if(s[i]==s[j]) continue;
		else {
			s[j]=s[i];
			wzt++;
		}
	}
	cout<<wzt;
	return 0;
}
