#include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int shizhi=0;
    int anweiyu[a][1000000];
    for(int i=1;i<=a;i++)
    {
    	cin>>shizhi;
    	while(shizhi!=0)
    	{
    		vector<int> er;
    		int yu=0;
    		yu=shizhi%2;
    		shizhi=shizhi/2;
    		er.push_back(yu);
		}
		vector<int> erjingzhi;
		for(int j=er.size()-1;j>=0;j--)
		{
			erjingzhi.push_back(er[j]);
		}
		for(int k=0;k<=erjingzhi.size();k++)
		{
			anweiyu[i][k]=erjingzhi[k];
		}
	}
	vector<string> zhengxu;
	for(int i=1;i<=a;i++)
	{
		string an=' ';
		for(int j=1;j<=erjingzhi.size();j++)
		{
			an+=anweiyu[i][j];
		}
		
	}
    return 0;
 } 
