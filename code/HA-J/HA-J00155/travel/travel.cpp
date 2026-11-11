#include<bits/stdc++.h>
#include<iostream>

using namespace std;

string c1,s1,c2,s2;

bool cnt;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	if(c1 == c2)
	{
		cout << 1;
		cnt = 1; 
	}
	else
	{
		cout << 0;
		cnt = 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1] && cnt)
	{
		cout << 1;
		cnt=1;
	}
	else
	{
		cout << 0;
		cnt=0;
	}
	if( (s1[2] < 'D' && s2[2] < 'D' || s1[2] > 'C' && s2[2] > 'C') && cnt)
	{
		cout << 1; 
		cnt=1;
	}
	else
	{
		cout << 0;
		cnt=0;
	}
	if (cnt && (abs(s1[2] - s2[2])==1 || s1[2]>'C' ) )
		cout << 1;
	else
		cout << 0;
	
	
	
	
	return 0;
}
