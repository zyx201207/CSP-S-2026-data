#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],qa[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,su;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		qa[i]=qa[i-1]+a[i];
		sum+=a[i];
	}
	string s,sl,sr;
	for(int i=1;i<=n;i++){
		for(int j=qa[i-1];j<=qa[i];j++){
			s+=c[i];
		}
	
	}int s1=s.size()-1;
	for(int i=1;i<=s1/2;i++){
		sl+=s[i];
	}
	for(int i=s1/2+1;i<=n;i++){
		sr+=s[i];
	}
	for(int i=1;i<=s1/2;i++){
		if(sl[i]!=sr[i])su++;
	}
	cout<<su;
	return 0;
}
