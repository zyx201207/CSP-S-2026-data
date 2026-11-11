#include <bits/stdc++.h>
#include <string.h>
#define ll long long 
#define endl "\n"
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)cout<<"1";
	else cout<<"0";
	
	string x=s1,y=s2;
	x.erase(x.begin()+2);
	y.erase(y.begin()+2);
	if(x==y&&c1==c2)cout<<"1";
	else cout<<"0";
	if(c1==c2&&x==y
	&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
	||((s1[2]=='D'||s1[2]=='E')
	&&(s2[2]=='D'||s2[2]=='E'))
	)cout<<"1";
	else cout<<"0";
	
	if(c1==c2&&x==y&&abs((int)s1[2]-s2[2])==1&&!((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')))cout<<"1";
	else cout<<"0";
	
	
	
	return 0;
}
