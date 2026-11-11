#include<bits/stdc++.h>
using namespace std;
string st1,st2,st3,st4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>st1>>st2>>st3>>st4;
	if(st1==st3)
	{
		cout<<1;
		if(st2[0]==st4[0] && st2[1]==st4[1])
		{
			cout<<1;
			if(int(st2[2])<=int('C') && int(st4[2]<=int('C')) || int(st2[2])>=int('D') && int(st4[2])>=int('D') && int(st2[2])<=int('F') && int(st4[2])<=int('F'))
			{
				cout<<1;
				if(int(st2[2])+1==int(st4[2]) && st2[2]!='C' || int(st2[2])-1==int(st4[2]) && st2[2]!='D')
				{
					cout<<1;
				}
				else cout<<0;
			}
			else
			{
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0;
}
