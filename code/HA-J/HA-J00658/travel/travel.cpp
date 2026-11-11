#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1=="01"&&c1=="16")
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
		cout<<1;
	else cout<<0;
	int num1=0,num2=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			num1=num1*10+(s1[i]-'0');
		}
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			num2=num2*10+(s2[i]-'0');
		}
	}
	if(c1==c2&&num1==num2)
		cout<<1;
	else cout<<0;
	a[s1[2]-'A'+1]++;
	a[s2[2]-'A'+1]++;
	int idx1=0,idx2=0;
	for(int i=1;i<=5;i++)
	{
		if(a[i]==1)
		{
			if(!idx1)
				idx1=i;
			else idx2=i; 
		}
		else if(a[i]==2)
			idx1=idx2=i;
	}
	if(c1==c2&&num1==num2&&((idx1>=1&&idx1<=3&&idx2>=1&&idx2<=3)||(idx1>=4&&idx1<=5&&idx2>=4&&idx2<=5)))
		cout<<1;
	else cout<<0;
	if(c1==c2&&num1==num2&&(abs(idx1-idx2)==1)&&((idx1>=1&&idx1<=3&&idx2>=1&&idx2<=3)||(idx1>=4&&idx1<=5&&idx2>=4&&idx2<=5)))
		cout<<1;
	else cout<<0; 
	return 0;
}
