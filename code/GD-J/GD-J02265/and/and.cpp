#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
char b[100010];
string s;
int m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s[i]=b[i];
		m+=a[i];
	}
	if(m%2==0)m/=2;
	else m=m/2;
	for(int i=1;i<=m+1;i++){
		if(b[i]!=b[n+1-i]){
		cout<<m;
		return 0;
	}
		else {
		cout<<0;
		return 0;
	}
	}
	return 0;
}
