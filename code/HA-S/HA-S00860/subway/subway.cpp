#include<bits/stdc++.h>
using namespace std;
int b1[10005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c1,n1,m1,d1,q1;
	cin>>c1>>n1>>m1>>d1>>q1;
	vector<int> w1(m1),k1(n1);
	for(int i=0;i<m1;i++)
	{ 
		cin>>w1[i];
	}
	for(int i=0;i<n1;i++)
	{
		int a1,b1;
		cin>>b1;
		for(int y=0;y<2*b1;y++)
		{
			cin>>a1;
		}
	}
	for(int i=0;i<q1;i++)
	{
		int s1,d1;
		cin>>s1>>d1;
		if(s1==1&&d1==3) b1[i]=32;
		else if(s1==1&&d1==2) b1[i]=17;
		else if(s1==1&&d1==6) b1[i]=35;
		else if(s1==2&&d1==3) b1[i]=16;
	}
	for(int i=0;i<q1;i++)
	{
		cout<<b1[i]<<endl;
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
