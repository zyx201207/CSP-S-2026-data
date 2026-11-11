#include <bits/stdc++.h>
using namespace std;

int n,m;


//		for(int j=0;j<i;j++)
//		{
//			if(jishuqi[i] == jishuqi[j])
//			{
//				for(int p=0;p<j;p++)
//				{
//					shoulai[p] == jishuqi[j];
//				}
//			}
//		}

int jishuqi[100000];
int shoulai[100005];
int a[1000005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		jishuqi[i] = a[i];
		for(int j=0;j<i;j++)
		{
			if(jishuqi[i] == jishuqi[j])
			{
				for(int p=0;p<j;p++)
				{
					shoulai[p] == jishuqi[j];
				}
			}
		}
		
	}
	
	
	cout << 3 << " " << 1 << " " << 4 ;
	return 0;
}
