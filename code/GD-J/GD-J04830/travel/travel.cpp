#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	int c1, c2;
	int cnt1, cnt2, cnt3, cnt4;
	string z1, z2;
	cin >> c1 >> z1 >> c2 >> z2;
	if(c1 == c2)
	{
		cnt1 = 1;
		//问题一 
		if(c1 == 1 || c2 == 1 || c1 == 16 || c2 == 16)//是否为二等 
		{
			cnt2 = 0;
			cnt3 = 0;
			cnt4 = 0;
		}
		else
		{
			if(z1[0] == z2[0] && z1[1] == z2[1])//是否同一排 , 问题二 
			{
				cnt2 = 1;
			}
			else
			{
				cnt2 = 0;
			}
			 if(((z1[2] >= 'A' || z1[2] <= 'C') && (z2[2] >= 'A' || z2[2] <= 'C')) || ((z1[2] >= 'D' || z1[2] <= 'F') && (z2[2] >= 'D' || z2[2] <= 'F')))//是否在过道同一侧 ， 问题三 
			{
				cnt3 = 1;
			}
			else
			{
				cnt3 = 0;
			}
			if((z1[2] + 1 != z2[2]) || (z1[2] - 1 != z2[2]))//看看是否邻座 ， 问题四 
			{	
				if((z1[2] != 'C' || z1[2] != 'D') && (z2[2] != 'C' || z2[2] != 'D'))
				{
					cnt4 = 0;
				}
			}
			else
			{
				cnt4 =1;
			}
		}
	cout << cnt1 << cnt2 << cnt3 << cnt4;//1
	}
	else if(c1 != c2)
	{
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		cnt4 = 0;
		cout << cnt1 << cnt2 << cnt3 << cnt4;
	}
	
	
	
	
	
	return 0;
}
