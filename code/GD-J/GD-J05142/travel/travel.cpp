#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,ah,bh;
	char aw,bw;
	bool q1,q2,q3,q4;
	cin>>ah>>a>>aw>>bh>>b>>bw;
	if(ah==bh) q1=1;
	else q1=0;
	if(a==b&&q1) q2=1;
	else q2=0;
	if(((aw>='D'&&bw>='D')||(aw<='C'&&bw<='C'))&&q2) q3=1;
	else q3=0;
	if(abs(aw-bw)==1&&q3) q4=1;
	else q4=0;
	cout<<q1<<q2<<q3<<q4; 
	return 0;
}
