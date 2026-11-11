#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	bool n,m,i,j;
	n=(cr==cx);
	cout<<n;
	int r=0,x=0;
	r=(sr[0]-'0')*10+(sr[1])-'0';
	x=(sx[0]-'0')*10+(sx[1])-'0';
	m=(r==x);
	cout<<(n&&m);
	char a=sr[2],b=sx[2];
	i=(a<='C'&&b<='C')||(a>='D'&&b>='D');
	cout<<(n&&m&&i);
	int num=abs(a-b);
	j=(num==1);
	cout<<(n&&m&&i&&j);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
