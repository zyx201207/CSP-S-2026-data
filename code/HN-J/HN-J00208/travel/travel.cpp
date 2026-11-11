#include<bits/stdc++.h>
using namespace std;
int shu(string a){
	int o=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		o*=10;
		o+=a[i]-'0';
	}
	return o;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[5],a[5];
	cin>>s[1]>>a[1]>>s[2]>>a[2];
	int cx1,cx2,cz1,cz2;
	cx1=shu(s[1]);
	cx2=shu(s[2]);
	
	if(cx1==cx2){
		cout<<1;
		if(a[1][2]==a[2][2])
		{
			cout<<'1';
			cout<<'1';
		}
		else cout<<"00";
		
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	a[1].erase(2,1);
	a[2].erase(2,1);
	cz1=shu(a[1]);
	cz2=shu(a[2]);
	if(cz1==cz2)cout<<'1';
	else cout<<'0';
}
