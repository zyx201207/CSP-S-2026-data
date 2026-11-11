#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	long long cnt=0,l=s.length();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
