#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate.in","r", stdin);
	freopen("migrate.out","w",stdout);
	int testpoint,testgroup;
	cin>>testpoint>>testgroup;
	int islandnumber,distance;
	int islanddata[testgroup][123456789];
	for(int groupnumber;groupnumber<testgroup;groupnumber++)
	{
		cin>>islandnumber>>distance;
		cin>>islanddata[groupnumber][0];
	}
	int islanddistance[100000];
	for(int islandTime=100000;islandTime>=0;islandTime++){
		islanddistance[islandTime] = islanddata[islandTime] - islanddata[islandTime-1];
		for(int TaskSymbol, sum;sum<=islandTime;sum++){
			
		}
	}
	return 0;
}

