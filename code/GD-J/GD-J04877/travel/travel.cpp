#include<bits/stdc++.h>
using namespace std;
int s1,s3;
string s2,s4;
map<char,int> a; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1 == s3 && s1 != 1 && s1 != 16)cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	a['A'] = 1;
	a['B'] = 1;
	a['C'] = 1;
	a['D'] = 2;
	a['F'] = 2;
	if(s2[0] != s4[0] || s2[1] != s4[1])
	{
		cout<<"000";
		return 0;
	 } 
	if(s2[0] == s4[0] && s2[1] == s4[1])
	{
		if(a[s2[2]] == a[s4[2]])cout<<"11";
		else cout<<"10";
	}
	else cout<<"00";
	if(a[s2[2]] == a[s4[2]] && s2[0] == s4[0])
	{
		if(a[s2[2]] == a[s4[2]])
		{
			if(a[s2[2]] == 1)
			{
				if(s2[2] == 'A' && s4[2] =='B' || s2[2] == 'B' && s4[2] =='A' || s2[2] == 'B' && s4[2] =='C' || s2[2] == 'C' && s4[2] =='B')cout<<1;
				else cout<<0;
			}
			else
			{
				cout<<0;
			}
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
