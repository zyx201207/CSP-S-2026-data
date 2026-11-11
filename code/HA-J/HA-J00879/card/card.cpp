#include <iostream>
using namespace std;
int n,m;
int num[10005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int k = 1;k <= n;k++)
		{
		    cin >> num[i];
		    if(num[i] == num[i+2])
		    {    
			    for(int j = 1;j <= n;j++)
			    {
				    num[j] == 0;
			    }
		    }
		    if(num[i] == num[n])
		    {
		        cout << num[k] << " ";
			}
		}
	}
	return 0;
}
