#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[100000005];
char s[100000005],s1[100000005],s2[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool f=1;
	cin>>n;
	int len=1;
	for(int i=1;i<=n;i++){
		char c; 
		cin>>a[i]>>c;
		m+=a[i];
		if((c!=s[len-1])&&(i!=1)) f=0;
		for(int j=1;j<=a[i];j++){
			s[len]=c;
			len++;
		}
	}
	if((m==1)||f){
		cout<<0;
		return 0;
	}
	long long ans=0,x;
	if(m%2==1) x=n/2+1;
	else x=n/2;
	for(int i=x+1;i<=m;i++)
		s2[i-x]=s[i];
	for(int i=1;i<x;i++)
		s1[i]=s[i];
	for(int i=1;i<=x;i++)
		if(s1[i]!=s2[i]) ans++;
	cout<<ans;
	return 0;
}
