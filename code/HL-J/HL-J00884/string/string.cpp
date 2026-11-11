#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l=0;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	l=s.size();
	int ans=0;
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i-1]) ans++;
	}
	cout<<ans/2;
	return 0;
}