#include<bits/stdc++.h>
using namespace std;
const int M=2e6+5;
long long n,a[M],cnt=0,l=1;
string s;
char c[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s[l]=c[i];
			l++;
		}
	}
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[l-i]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
