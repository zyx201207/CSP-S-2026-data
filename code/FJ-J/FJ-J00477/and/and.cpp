#include<bits/stdc++.h> 
using namespace std;
int arr[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	cout<<arr[m-1];
	return 0;
}

