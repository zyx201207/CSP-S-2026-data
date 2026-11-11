//贵阳中天中学裴天元GZ-J00687
#include<bits/stdc++.h>
using namespace std;
string r_x,r_y,x_x,x_y,/*dui[5]={'A','B','C','D','F'}*/dui="ABCDF";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_x>>r_y>>x_x>>x_y;
	bool a_1=(r_x==x_x),a_2=0,a_3=0,a_4=0;
	string r_y_s=""+r_y[0]+r_y[1],x_y_s=""+x_y[0]+x_y[1];
	char r_y_z=r_y[2],x_y_z=x_y[2];
	a_2=a_1 and (r_y_s==x_y_s);
	if (a_2==0){cout<<a_1<<"000";return 0;}
	for (int i=0;i<5;i++)
	{
		//cout<<r_y_z<<endl;
		if (r_y_z==dui[i])
		{
			if ('A'<=dui[i] and dui[i]<='C')
			{
				for (int j=0;j<3;j++)
				{
					if (x_y_z==dui[j])
					{
						a_3=1;
						if (abs(i-j)==1)a_4=1;
						break;
					}
				}
			}
			if (dui[i]=='D' or dui[i]=='F')
			{
				for (int j=3;j<5;j++)
				{
					if (x_y_z==dui[j])
					{
						a_3=1;
						if (abs(i-j)==1)a_4=1;
						break;
					}
				}
			}
			break;
		}
	}
	cout<<a_1<<a_2<<a_3<<a_4;
	return 0;
} 
