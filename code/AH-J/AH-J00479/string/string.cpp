#include<bits/stdc++.h>
using namespace std;
const int T=2*1e5+10;
string s;
int n;
long long diff,a[T];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)s+=c;
	}
	string s1=s;
	reverse(s.begin(),s.end());
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]!=s1[i])
			diff++;
	cout<<diff/2;
	return 0;
}
