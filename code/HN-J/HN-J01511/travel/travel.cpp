#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
int sum;

void in(int &x)
{
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}

void out(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else if(s1.substr(0,2)!=s2.substr(0,2)) cout<<"1000";
	else
	{
		int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
		if(a<=3) sum++;
		if(b<=3) sum++;
		if(sum!=2) cout<<"1100";
		else if(abs(a-b)!=1) cout<<"1110";
		else cout<<"1111";
	}
	return 0;
}
