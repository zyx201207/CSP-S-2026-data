#include<bits/stdc++.h>
using namespace std;
struct tic{
	string cx;
	string zh;
}a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,i,j,x;
	cin>>a1.cx;
	cin>>a1.zh;
	cin>>a2.cx;
	cin>>a2.zh;
	/*for(i=0;i<a1.zh.size();i++)
	{
		cout<<a1.zh[i];
	}*/
	if(a1.cx==a2.cx)
	{
		cout<<1;
		if(a1.zh[0]+a1.zh[1]==a2.zh[0]+a2.zh[1])
		{
			cout<<"1";
			if((a1.zh[2]<='C'&&a2.zh[2]<='C')||(a1.zh[2]>='D'&&a2.zh[2]>='D'))
			{
				cout<<"1";
				char c1=a1.zh[2],c2=a2.zh[2];
				//cout<<c1<<' '<<c2<<endl;
				if(c1-c2==1||c2-c1==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
} 
