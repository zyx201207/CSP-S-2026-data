#include <bits/stdc++.h>
using namespace std;

int n;
char zimu[200005];
int geshu[200005];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>geshu[i]>>zimu[i];
	} 
	
	int i=0,j=n-1;
	long long cnt = 0;
	while(i <= j)
	{
		int mn = min(geshu[i], geshu[j]);
		if(zimu[i] != zimu[j])
		{
			cnt += mn;
		}
		geshu[i] -= mn;
		if(geshu[i] == 0) i++;
		geshu[j] -= mn;
		if(geshu[j] == 0) j--;
	}
	cout<<cnt; 
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


