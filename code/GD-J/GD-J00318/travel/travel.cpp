#include<bits/stdc++.h>
using namespace std;
int r1,r2,c1,c2;
char n1,n2;
void output(bool r)
{
	if(r)cout <<1;
	else cout <<0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>r1>>c1>>n1>>r2>>c2>>n2;
	output(r1==r2);
	if(r1!=r2)
	{
		cout <<"000";
		return 0;
	}
	bool check1=(c1==c2),check2=check1&&((n1<'D')==(n2<'D'));
	output(check1);
	output(check2);
	if(check1)
	{
		if(n2<n1)swap(n1,n2);
		bool check3=(abs(n2-n1)==1&&n2!='D')||(n2=='F'&&n1=='D');
		output(check3);
	}
	else
	{
		bool check3=(abs(c2-c1)==1)&&(n1==n2);
		output(check3);
	}
	return 0;
}
