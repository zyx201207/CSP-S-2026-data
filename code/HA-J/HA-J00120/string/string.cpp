#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10000005],q[10000005],cnt=0;
string s;
char c[10000005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int  i=1; i<=n; i++) {
		cin>>a[i];
		t+=a[i];
		q[i]=a[i]+q[i-1];
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=q[i-1];j<q[i];j++)
		s[j]=c[i];
	}
	for(int i=0;i<t/2+1;i++){
		if(s[i]!=s[t-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
