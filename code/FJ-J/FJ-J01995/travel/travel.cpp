#include<bits/stdc++.h>
using namespace std;
string c,s,nc,ns;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp['A']=1;mp['B']=1;mp['C']=1;
	mp['D']=2;mp['F']=2;
	cin>>c>>s>>nc>>ns;
	if(c==nc)cout<<1;
	else
	{
	 	cout<<"0000";
	 	exit(0);
	}	
	
	string a=s.substr(0,2);
	string b=ns.substr(0,2);
	if(a==b)cout<<1;
	else 
	{
		cout<<"000";
		exit(0);
	}
	char d=s[2];
	char f=ns[2];
	if(mp[d]==2&&mp[f]==2)
	{
		cout<<"11";
		exit(0);
	}
	if(mp[d]==mp[f])cout<<1;
	else
	{
		cout<<"00";
		exit(0);
	}
	int e=(int)d-64;
	int g=(int)f-64;
	if(abs(e-g)==1)cout<<1;
	else cout<<0;
	return 0;
}