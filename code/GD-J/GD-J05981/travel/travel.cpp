#include<bits/stdc++.h>
using namespace std;
int main()
{
	string c1,s1,c2,s2;
	int panduan=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	cout<<'1';
	for(int i=0;i<2;i++)
	{
		if(s1[i]==s2[i])
		{
			panduan++;
		}
	 } 
	 if(panduan==2)
	 {
	 	cout<<'1';
	 	int k1=0,k2=0;
	 	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')k1=0;
	 	else
		{
	 		k1=1;	
		 }
		 if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')k2=0;
	 	else
		{
	 		k2=1;	
		 }
		 if(k1==k2)
		 {
		 cout<<'1';
		 int a1=char(s1[2]),a2=char(s2[2]);
		 if(a1==a2-1||a1==a2+1)
		 {
		 	cout<<'1';
		 }
		 else
		 {
		 	cout<<'0';
		 }
		 }
	 	else{
	 		cout<<'0'<<'0';
		 }
	 }
	 else
	 {
	 	cout<<'0'<<'0'<<'0';
	 }
	 }
	 else if(c1!=c2)
	 {
	 	cout<<'0'<<'0'<<'0'<<'0';
	 }
	 
	return 0;
}
