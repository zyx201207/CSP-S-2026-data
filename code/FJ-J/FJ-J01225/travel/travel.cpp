#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	string same;
	
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2)
		same="1";
	else
		same="0";
	
	if ((s1[0]==s2[0]&&s1[1]==s2[1])&&same[0]==49)
		same=same+"1";
	else
		same=same+"0";
		
	if (((s1[2]<68&&s2[2]<68)||(s1[2]>67&&s2[2]>67))&&same[1]==49)
		same=same+"1";
	else
		same=same+"0";
		
	if (((s1[2]==s2[2]+1)||(s2[2]==s1[2]+1))&&same[2]==49)
		same=same+"1";
	else
		same=same+"0";
		
	cout<<same<<endl;;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
 } 
