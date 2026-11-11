#include<bits/stdc++.h> 
using namespace std;
char c;
int flag=1,num,sum;
int pl[10][10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	while(1)
	{
		scanf("%c",&c);
		if(c=='\r'||c=='\n')
		{
			int x=(flag-1)/3+1,y=(flag-1)%3+1;
			pl[x][y]=sum;
			flag++;
			sum=0;
			break;
		}
		if(c==' ')
		{
			int x=(flag-1)/3+1,y=(flag-1)%3+1;
			pl[x][y]=sum;
			flag++;
			sum=0;
			continue;
		}
		if('0'<=c&&c<='9')
		{
			num=int(c-'0');
			sum=sum*10+num;
		}
		else if('A'<=c&&c<='F')
		{
			int x=flag/3+1,y=(flag-1)%3+1;
			pl[x][y]=sum;
			flag++;
			sum=0;
			num=int(c-'A'+1);
			sum=sum*10+num;
		}
	}
	if(pl[1][1]!=pl[2][1])
	{
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(pl[1][2]!=pl[2][2])
	{
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	int a=(pl[1][3]-1)/3,b=(pl[2][3]-1)/3;
	if(a!=b)
	{
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(pl[1][3]==pl[2][3]+1||pl[2][3]==pl[1][3]+1)
	{
		cout<<"1";
		return 0;
	}
	else cout<<"0";
	return 0;
}
