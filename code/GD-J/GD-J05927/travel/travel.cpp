#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int A=0,B=0;
	string a,b,as="";
	
	cin>>A>>a>>B>>b;
	if (A == B){
		as += "1";
		string la,lb;
		la = a[0]+a[1];
		lb = b[0]+b[1];
		if (la==lb)
		{
			as += "1";
			la = a[2];
	    	lb = a[2];
			if ((la<="C"&& lb<="C")||(la>"C"&& lb>"C")) {
				as+="1";
				
				if((la =="A"&&lb=="C")||(la =="C"&&lb=="A"))
				{
					as += "0";
				}
				else as+="1";
		    }
			else as += "00";
		}
		else as += "000";
		} 
	else as += "0000";
	
	cout<<as;
	return 0 ;
 } 
