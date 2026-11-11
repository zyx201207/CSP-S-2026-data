 #include<bits/stdc++.h>
 using namespace std;
 bool c1=0,c2=0,c3=0,c4=0;
 int main()
 {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	c1=r1==x1;
	if(r1[0]==x1[0]&&r1[1]==x1[1])
	{
		c2=1;
		if((r2[2]<='C'&&x2[2]<='C')||(r2[2]>'C'&&x2[2]>'C'))
		{
			c3=1;
			if((r2[2]==x2[2]+1&&r2[2]!='C')||(r2[2]+1==x2[2]&&x2[2]!='C'))
				c4=1;
		}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
 }
