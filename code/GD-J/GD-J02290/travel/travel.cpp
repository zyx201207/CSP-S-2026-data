#include <iostream>
#include <string>
using namespace std;

int main()
{
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;	
	if(c1==c2)
	{
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	if(s1[1]==s2[1]) 
	{
		cout << "1";
	}
	else
	{
		cout << "000";
		return 0;
	}
	if(s1[2]<=66||s2[2]<=66)
	{	    
		cout << "1";
	}
	else
	{
		cout << "00";
		return 0;
	}
	if(s1[2]+=s2[2])
	{		     
	    cout << "1";		
	}	
	else{				
		cout << "0";
	}
	return 0;
} 
