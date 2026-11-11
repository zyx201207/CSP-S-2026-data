#include<bits/stdc++.h>
using namespace std;
string box1,box2,wei1,wei2;
bool check(char a,char b)
{
	if(a<='C'&&(char(a+1)==b||char(b+1)==a)) return 1;
	else if(a>='D'&&a!=b) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>box1>>wei1>>box2>>wei2;
	if(box1==box2)
	{
		cout<<1;
		if(wei1[0]==wei2[0]&&wei1[1]==wei2[1])
		{
			cout<<1;
			if((wei1[2]<='C'&&wei2[2]<='C')||(wei1[2]>='D'&&wei2[2]>='D'))
			{
				cout<<1;
				cout<<check(wei1[2],wei2[2]);
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
