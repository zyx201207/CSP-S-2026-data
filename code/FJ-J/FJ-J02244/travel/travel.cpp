#inslude<iostream>
#inslude<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int x=1; 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		x=0;
	}
	if(x==1&&s1(0,1)==s2(0,1))
	{
		cout<<1;
	}
	else{
		cout<<0;
		x=0;
	}
	if(x==1&&((s1(2)>=C&&s2(2)>=c)||(s1(2)<C&&s2(2)<c)))
	{
		cout<<1;
	}
	else{
		cout<<0;
		x=0;
	}
	if(x==1&(s1-1==s2||s1+1==s2))
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
