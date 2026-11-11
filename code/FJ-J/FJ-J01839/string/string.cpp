#include<bits/stdc++.h>
using namespace std;
long long a,s,d,l,v;
string q;
char t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>s;
		cin>>t;
		l+=s;
		for(int j=1;j<=s;j++)
			q[j+d]=t;
		d+=s;
	}
	for(int i=1;i<=l/2;i++){
		if(q[i]!=q[l-i+1])
			v++;
	}
	cout<<v;
	return 0;
}
