#include <iostream>
#include <algorithm>
using namespace std;
long long arr[200005] = {0};
int n,m;
long long t_p;

int main()
{
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0;i < n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<arr[m-1];
	
	return 0;
}
