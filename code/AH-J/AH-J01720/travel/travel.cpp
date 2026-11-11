#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin,s);
//    cout<<s[0]<<" "<<s[7]<<" "<<s[1]<<" "<<s[8]<<"\n";
    if(s[0]==s[7]&&s[1]==s[8])
    {
    	cout<<1;
	}
	else cout<<0;
	if((s[0]==s[7]&&s[1]==s[8])&&(s[3]==s[10]&&s[4]==s[11]))
	{
		cout<<1;
	}
	else cout<<0;
	int a=0,b=0;
	if(s[5]<='C')a=1;
	if(s[12]<='C')b=1;
	if((s[0]==s[7]&&s[1]==s[8])&&(s[3]==s[10]&&s[4]==s[11])&&a==b)
	{
		cout<<1;
	}
	else cout<<0;
	if((s[0]==s[7]&&s[1]==s[8])&&(s[3]==s[10]&&s[4]==s[11])&&a==b&&!((s[5]=='A'&&s[12]=='C')||(s[5]=='C'&&s[12]=='A')))
	{
		cout<<1;
	}
	else cout<<0;
    return 0;
}
