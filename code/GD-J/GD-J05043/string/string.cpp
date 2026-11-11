#include<bits/stdc++.h>
using namespace std;
long long len,cnt=0,t,a[200005];
char b[200005];
int n;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++)c+=b[i];
	}
	len=c.size();
	t=len-1;
	for(long long i=0;i<len/2;i++){
		if(c[i]!=c[t])cnt++;
		t--;
	}
	cout<<cnt;
	return 0;
}
