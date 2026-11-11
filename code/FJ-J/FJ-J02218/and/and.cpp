#include<bits/stdc++.h>
using namespace std;
int a[200500];
bool cmp(int a,int b) {
	return a>b;
}
int fun(int a,int b) {
	string s1,s2;
	int len1=0;
	int t=a;
	while(t) {
		s1[len1]=t%2+'0';
		t/=2;
		len1++;
	}
	t=b;
	int len2=0;
	while(t) {
		s2[len2]=t%2+'0';
		t/=2;
		len2++;
	}
	string s;
	int len=min(len1,len2);
	for(int i=0; i<len; i++) {
		if(s1[i]=='1'&&s2[i]=='1') {
			s[i]='1';
		} else if(s1[i]=='1'&&s2[i]=='0'||s1[i]=='0'&&s2[i]=='0'||s1[i]=='0'&&s2[i]=='1') {
			s[i]='0';
		}
	}
	int c,z=1;
	for(int i=0; i<len; i++) {
		int p=s[i]-'0';
		c+=p*z;
		z*=2;
	}
	return c;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int num=fun(a[1],a[2]);
	for(int i=2; i<m; i++) {
		num=fun(num,a[i+1]);
	}
	if(m==1) {
		cout<<0;
		return 0;
	}
	cout<<num;
	return 0;
}