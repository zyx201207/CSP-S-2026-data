#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	string s1,t1,s2,t2;
 	cin>>s1>>t1>>s2>>t2;
 	if (s1==s2) 
	{
	 	cout<<1;
		string a=t1.substr(0,2),b=t2.substr(0,2);
 		if (a==b) 
		{
		 	cout<<1;
			char x=t1[2],y=t2[2];
 			if (((x=='A' || x=='B' || x=='C') && (y=='A' || y=='B' || y=='C'))||((x=='D' || x=='F') && (y=='D' || y=='F')))
			{
				cout<<1;
				if ((x=='A' && y=='B') || (x=='B' && y=='C') || (x=='D' && y=='F') || (x=='B' && y=='A') || (x=='C' && y=='B') || (x=='F' && y=='D'))
					cout<<1;
				else cout<<0;
			}
			else cout<<"00";				
		}
 		else cout<<"000";
	}
 	else cout<<"0000";
	return 0;
} 
