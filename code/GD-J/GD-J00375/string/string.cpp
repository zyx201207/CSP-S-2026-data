#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;

const long long MAXN=20005;
long long n,a[MAXN],cnt1,cnt2;
char s[MAXN];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string str1;
	string str2;
	string str3;
	string half1;
	string half2;
	a[1]=0;
	for(long long i=1;i<=n;i++) {
		cin>>a[i]>>s[i];
		for(long long j=1;j<=a[i];j++) {
			str1+=s[i];
		}
	}
	long long L=str1.size();
	if(L%2==0) {
		for(long long i=1;i<=L/2;i++) {
			half1+=str1[i-1];
			str2+=str1[i-1];
		}
		for(long long i=half1.size()-1;i>=0;i--) {
			str2+=half1[i];
		}
		for(long long i=L-1;i>=L/2;i--) {
			half2+=str1[i];
		}
		for(long long i=1;i<=half2.size();i++) {
			str3+=half2[i-1];
		}
		for(long long i=half2.size()-1;i>=0;i--) {
			str3+=half2[i];
		}
	}
	else if(L%2==1) {
		for(long long i=1;i<=L/2+1;i++) {
			half1+=str1[i-1];
			str2+=str1[i-1];
		}
		str2+=str1[L/2];
		for(long long i=half1.size()-1;i>=0;i--) {
			str2+=half1[i];
		}
		for(long long i=L-1;i>=L/2+1;i--) {
			half2+=str1[i];
		}
		for(long long i=1;i<=half2.size();i++) {
			str3+=half2[i-1];
		}
		str3+=str1[L/2];
		for(long long i=half2.size()-1;i>=0;i--) {
			str3+=half2[i];
		}
	}
	for(long long i=0;i<=L;i++) {
		if(str2[i]!=str1[i])	cnt1++;
		if(str3[i]!=str1[i])	cnt2++;
	}
	cout<<min(cnt1,cnt2);
	return 0;
}
