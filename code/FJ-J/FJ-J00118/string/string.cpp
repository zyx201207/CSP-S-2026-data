#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,flag=0;
	cin>>n;
	int a[n+5],f;
	char c[n+5],l[1000005],m[1000005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			l[flag+j]=c[i];
		flag=flag+a[i];
			
}
	f=flag;
	for(int i=1;i<=flag;i++){
		m[i]=l[f];
		f--;
	}
	for(int i=1;i<=flag;i++){
		m[i]!=l[i];
		s++;
	}
	cout<<s;
	
	return 0;
}
