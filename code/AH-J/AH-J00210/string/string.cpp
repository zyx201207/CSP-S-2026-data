#include<bits/stdc++.h>
using namespace std;
long long n,l,cnt,a[200005];
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		l+=a[i];
		while(a[i]--)
			s+=c;
	}
	for(int i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			cnt++;
	cout<<cnt;
	return 0;
}
