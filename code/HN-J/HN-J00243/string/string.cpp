#include<bits/stdc++.h>
using namespace std;
long long x,n,m,sum;
char y;
string s,s1;
int ch(){
	long long k=0;
	for(long long i=n-1;i>=0;i--)s1[k]=s[i],k++;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(long long i=1;i<=m;i++){
		cin>>x>>y;
		for(long long j=n;j<n+x;j++)s[j]=y;
		n+=x;
	}
	ch();
	n++;
	n/=2;
	for(long long i=0;i<n;i++)if(s[i]!=s1[i])sum++;
	cout<<sum<<endl;
	return 0;
}
