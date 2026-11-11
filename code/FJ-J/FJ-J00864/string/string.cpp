#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,x;
char q;
long long c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>q;
		for(int j=1;j<=a;j++){
			s+=q;
			x+=q;
		}
	}
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]!=x[i]) c++;
	}
	cout<<c/2;
	return 0;
}
