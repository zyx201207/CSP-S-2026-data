#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0,sum=0;
char ch;
char s[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>ch;
		for(long long j=p;j<p+m;j++){
			s[j]=ch;
		}
		p+=m;	
	}	
	for(long long i=0;i<p;i++){
		long long x=p-i-1;
		if(s[i]!=s[x])sum++;
		if(i==x||i+1==x)break;
	}
	cout<<sum;
	return 0;
}
