#include <iostream>
#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	 cout<<1;
	else
	cout<<0;
	if (s1[1]==s2[1] && s1[2]==s2[2])
	cout<<1;	
	else
	cout<<0;
	if(s1[3]=='A'&&s2[3]=='b')
	cout>>1;
	else
	cout<<0;
	return 0;
}       
