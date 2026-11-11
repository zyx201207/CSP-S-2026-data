#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char s[n];
	string s1;
	long long a[n];
	long long step=0,sum=0;
	cin>>n;
	for(long long i=0;i<n;i++) {
		cin>>a[i]>>s[i];
		sum+=a[i];
		for(long long j=0;j<a[i];j++){
			s1+=s[i];
		}
	}
	for(long long j=0;j<sum/2;j++){
		if(s1[j]!=s1[sum-j-1]){
			step++;
		}
	}
	cout<<step/2;
}
