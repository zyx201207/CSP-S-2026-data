#include <bits/stdc++.h>
using namespace std;
int v1,v2;
string s1,s2;
int flag;
int abab[10]={1,1,1,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	flag=1;
	cin>>v1>>s1>>v2>>s2;
	if(v1!=v2)flag=0;
	cout<<flag;
	if(s1[1]!=s2[1] or s1[0]!=s2[0])flag=0;
	cout<<flag;
	v1=(int)s1[2]-'A';
	v2=(int)s2[2]-'A';
	if(abab[v1]!=abab[v2])flag=0;
	cout<<flag;
	if(abs(1-v2)==1)flag=0;
	cout<<flag;
	return 0;
}
