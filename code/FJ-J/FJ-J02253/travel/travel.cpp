#include<bits/stdc++.h>
using namespace std;
string ce1,cx1,ce2,cx2;
char z,x;
string n,m;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>ce1>>cx2>>ce2;
	if(cx1!=cx2)
	{
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		for(int i=0;i<3;i++)
		{
			if(i<2)
			{
				n=ce1[i];
				m=ce2[i];
			}
			z=ce1[2];
			x=ce2[2];
//			cout<<n<<" "<<m<<endl;
		} 
		for(int i=0;i<3;i++)
		{
			if(m==n)	
			{
				cout<<1;
				if((z=='D'&&x=='f')||(z=='F'&&x=='D')) 
				{
					cout<<11;
					return 0;
				}
				if((z=='A'||z=='B'||z=='C')&&(x=='A'||x=='B'||x=='C'))
				{
					cout<<1;
					if((z=='A'&&x=='B')||((z=='B'&&x=='A')||(z=='B'&&x=='C'))||(z=='C'&&x=='B')) {
						cout<<1;
						return 0;
					}
					else cout<<0;
					return 0;
				}
				if((z<='C'&&x>='C')||(z>='C'&&x<='C'))
				{
					cout<<"00";
					return 0; 
				}
			}
			else{
				cout<<"000";
				return 0;
			}
		}
	}
	return 0;
}
