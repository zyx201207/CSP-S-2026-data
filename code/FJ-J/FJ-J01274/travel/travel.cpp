#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ans1 = 0;
	int ans2 = 0;
	int ans3 = 0;
	int ans4 = 0;
	string c1,s1,c2,s2;
	string pai1,pai2;
	cin>>c1>>s1>>c2>>s2;//c是车厢号，s是座位号 
	if(c1 == c2) ans1 = 1;
	else ans1 = 0;
	
	pai1 = s1[0]+s1[1];
	pai2 = s2[0]+s2[1];
	
	if(pai1 == pai2 && ans1 == 1) ans2 = 1;
	else ans2 = 0;
	
	if(pai1 == pai2 && ans1 == 1 && ans2 == 1)
	{
		if(s1[2] <= 'C'&& s2[2] <= 'C') ans3 = 1;
		else if(s1[2] >= 'D' &&s2[2] >= 'D') ans3 = 1;
		else ans3 = 0;
	}
	else ans3 = 0;
	
	if(ans1 == 1&&ans2 == 1&&ans3==1)
	{
		if(s1[2] == 'A' && s2[2] == 'B') ans4 = 1;
		else if(s1[2] == 'B' && s2[2] == 'C') ans4 = 1;
		else if(s1[2] == 'B' && s2[2] == 'A') ans4 = 1;
		else if(s1[2] == 'C' && s2[2] == 'B') ans4 = 1;
		else if(s1[2] == 'D' && s2[2] == 'F') ans4 = 1;
		else if(s1[2] == 'F' && s2[2] == 'D') ans4 = 1;
		else ans4 = 0;
	}
	else ans4 = 0;
	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
	
	
	
	
}
