#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1; else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1; else cout<<0;
	if((s1[2]<='C'&&s2[2]<='C' || s1[2]>='D'&&s2[2]>='D')&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1; else cout<<0;
	if(abs(s1[2]-s2[2])==1 &&(s1[2]<='C'&&s2[2]<='C' || s1[2]>='D'&&s2[2]>='D')&&s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2) cout<<1; else cout<<0;
	return 0;
} 
