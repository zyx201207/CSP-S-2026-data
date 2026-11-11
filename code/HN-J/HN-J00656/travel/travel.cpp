#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1 == c2)cout<<1;
	else cout<<0;
	if(c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1])cout<<1;
	else cout<<0;
	if(c1 == c2 && s1[2] == 'C' && s2[2] == 'D' )cout<<0; 
	else if(c1 == c2 && s1[2] == 'D' && s2[2] == 'C')cout<<0; 
	else if(c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && 67<=s1[2]<=70 && 67<=s2[2]<=70)cout<<1;
	else if((c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'D' && s2[2] == 'F') || (c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'F' && s2[2] == 'D'))cout<<1;
	else cout<<0;
	if(c1 == c2 && s1[2] == 'A' && s2[2] == 'B')cout<<1;
	else if(c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'B' && s2[2] == 'A' || c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'B' && s2[2] == 'C' || c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'D' && s2[2] == 'F' || c1 == c2 && s1[0]==s2[0] && s1[1] == s2[1] && s1[2] == 'F' && s2[2] == 'D')cout<<1;
	else cout<<0;
	return 0;
}
