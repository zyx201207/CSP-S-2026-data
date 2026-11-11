#include<bits/stdc++.h>
using namespace std;
char str[5][3];
int a[3][3],b[3][4],c[5],ans,sum;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>str[1]>>str[2]>>str[3]>>str[4];
	for(int i=1;i<=4;i++)
	{
		if(i%2==1)
		{
			a[i/2+1][1]=str[i][0]-'0';
			a[i/2+1][2]=str[i][1]-'0';
		}
		else
		{
			b[i/2][1]=str[i][0]-'0';
			b[i/2][2]=str[i][1]-'0';
			b[i/2][3]=str[i][2]-'A'+1;
		}
	}
	for(int i=1;i<=2;i++)
	{
		if(a[1][i]!=a[2][i])
		ans++;
		if(b[1][i]!=b[2][i])
		sum++;
	}
	if(ans==0) c[1]=1;
	if(sum==0&&ans==0) c[2]=1;
	if(b[1][3]>=1&&b[1][3]<=3&&c[2]==1)
	{
		if(b[2][3]>=1&&b[2][3]<=3)
			c[3]=1;
	}
	else
	{
		if(b[2][3]>=4&&b[2][3]<=5&&c[2]==1)
			c[3]=1;
	}
	if(c[3]==1)
	{
		if(b[1][3]-b[2][3]==1||b[2][3]-b[1][3]==1)
			c[4]=1;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
