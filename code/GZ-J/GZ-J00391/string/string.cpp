#include <bits/stdc++.h>
using namespace std;

char s[2000000000000];
char s1[200000000000];

int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int a,b,c=0,e=0,g=0,h=0;
	char d;
	cin >> a;
	for(int i=0;i<a;i++){
		cin >> b;
		cin >> d;
		for(int j=0;j<b;j++){
			s[c]=d;
			c++;
			e++;
			g++;
		}}
	for(int i=0;i<g;i++){
		s1[e]=s[i];
		e-=1;
	}
	for(int i=0;i<g;i++){
		if(s1[i]!=s[i]){
			h++;
		}}
	if(h=0)
	cout << 0;
	else
	cout << h-1;
	return 0;
}
