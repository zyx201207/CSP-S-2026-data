//GZ-S00306  贵州省  遵义一中 邓卓远 
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int r,l;
bool v1,v=false;
int dpa[2000006],dpb[2000006];  
int sum[2000006];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i = 0;i < t;i++)
    {
    	cin >> n >> d;
    	r = 0;
    	v1 = false;
    	for(int j = 0;j < n;j++)
    	{
    		cin >> sum[i];
    		if(v1 == false && sum[i] - sum[r] > d)
    		{
    			v1 = true;
    			l = i;
			}
			dpa[0] = 0;
			if(j > 0)
			{
				for(int x = 0;x < j;x++)
				{
					if(sum[x] + d >= sum[j])
					{
						dpa[j] = dpa[x]+1;
						break;
					}
				}
			}
			if(j<n-1)
			{
				for(int x = j+1;x < n;x++)
				{
					if(sum[j] + d >= sum[x])
					{
						dpb[j] = x-1;
					}
				}
			}
		}
		for(int z = 0;z < n;z++)
		{
			cout << dpa[z]<<' ';
		}
		cout << endl;
		for(int z = 0;z < n;z++)
		{
			cout << dpb[z]<<' ';
		}
	}
	return 0; 
}

