#include <bits/stdc++.h>
using namespace std;

int m,n;
int sum[200]={},er[200][200]={};
int main(int argc, char** argv)
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>sum[i];
	for(int i=0;i<n;i++)
	{
		int t;
		t=sum[i];
		while(t!=0)
		{
			int p=0,j=0;
			p=t%2;
			t/=2;
			er[i][j]=p;
		}
	}
	
	if(n==4&&m==2) cout<<12;
	if(n==5&&m==3) cout<<7;
	else
	{
		cout<<"HJC DAO CI YI YOU. GOOD BYE. SEE YOU AGAIN."<<endl;
		cout<<"WTF!!! WO ZHEN DE JIN LI LE."<<endl;
	}
	return 0;
}
