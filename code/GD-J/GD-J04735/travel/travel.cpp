#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int s[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x) cout<<1;
	else 
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0] && b[1]==y[1]) cout<<1;
	else 
	{
		cout<<"000";
		return 0;
	}
	if((b[2]>='A' && b[2]<='C') && ((y[2]>='A' && y[2]<='C'))) cout<<1;
	else if((b[2]=='D' || b[2]=='F') && ((y[2]=='D' && y[2]<='F'))) cout<<1;
	else 
	{
		cout<<"00";
		return 0;
	}
	s[b[2]-'A']++;
	s[y[2]-'A']++;
	if(s[0]==1 && s[1]==1) cout<<1;
	else if(s[1]==1 && s[2]==1) cout<<1;
	else if(s[3]==1 && s[5]==1) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
