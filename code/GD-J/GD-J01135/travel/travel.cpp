#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f1=false,f2=false,f3=false,f4=false;
	cin >> c1 >> s1 >> c2 >> s2;
	int sit1=(s1[0]-'0')*10+(s1[1]-'0');
	int sit2=(s2[0]-'0')*10+(s2[1]-'0');
	int cit1=s1[2]-'A';
	int cit2=s2[2]-'A';
	if(c1==c2)
		f1=true;
	else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(sit1==sit2)
		f2=true;
	if((sit1==sit2)&& ((cit1<=5 && cit1>=3 && cit2>=3 && cit2<=5) || (cit1>=0 && cit1<=2 && cit2>=0 && cit2<=2)))
			f3=true;
	if(cit1<=1)
	{
		if((sit1==sit2 && cit1+1==cit2)||(cit1==cit2 && sit1+1==sit2)
		||(sit1==sit2&&cit1-1==cit2)||(cit1==cit2&&sit1-1==sit2))
			f4=true;//else cout<<0;
	}else if(cit1==5)
	{
		if((cit1==cit2 && sit1+1==sit2)
		||(sit1==sit2&&cit1-2==cit2)||(cit1==cit2&&sit1-1==sit2))
			f4=true;//else cout<<0;
	}else if(cit1==3)
	{
		if((sit1==sit2 && cit1+2==cit2)||(cit1==cit2 && sit1+1==sit2)
		||(cit1==cit2&&sit1-1==sit2))
			f4=true;//else cout<<0;
	}else if(cit1==2)
	{
		if((cit1==cit2 && sit1+1==sit2)
		||(sit1==sit2&&cit1-1==cit2)||(cit1==cit2&&sit1-1==sit2))
			f4=true;//else cout<<0;
	}//else cout<<0;
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
