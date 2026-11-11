#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;getline(cin,s);
	int a=(s[0]-'0')*10+(s[1]-'0');
	int b=(s[3]-'0')*10+(s[4]-'0');
	char c=s[5];
	int d=(s[7]-'0')*10+(s[8]-'0');
	int e=(s[10]-'0')*10+(s[11]-'0');
	char f=s[12];
	bool g=(a==d);
	bool h=(g&&(b==e));
	bool i=(h&&((c<='C')==(f<='C')));
	bool j=(i&&(abs(c-f)==1));
	cout<<g<<h<<i<<j;
	return 0;
}
