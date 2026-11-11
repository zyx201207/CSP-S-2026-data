#include <bits/stdc++.h>
using namespace std;
int n;
long long a,l,cnt;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	l=s.length()-1;
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
