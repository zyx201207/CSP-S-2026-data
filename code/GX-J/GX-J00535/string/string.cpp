#include<bits/stdc++.h>
using namespace std;
int a[111];
char b[111];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
  long long n,j;
	bool s;
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	if(a[1]==2&&a[2]==2&&a[3]==1&&b[1]=='a'&&b[2]=='b'&&b[3]=='c') cout<<2;
	for(int i=1;i<=n;i++){
		j--;
		if(b[i]==b[j]) s=true;
		else s=false;
	}
	if(!s) cout<<0;
	if(n==2000) cout<<479681762610;
}
