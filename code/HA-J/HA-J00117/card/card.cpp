#include <bits/stdc++.h>
using namespace std;
int arr[1024];
int main(int argc, char** argv)
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin<<arr[i];
	}
	
	for(int i=0;i<m;i++)
	{
		srand(time(0));
		cout<<rand()%n+1;
	}
	return 0;
}
