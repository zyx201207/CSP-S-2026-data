#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1,car2,set1,set2;
	cin>>car1>>set1>>car2>>set2;
	if(car1 == car2) cout<<1;
	else cout<<0;

	if(car1 == car2 && set1[0] == set2[0] && set1[1] == set2[1])
	{
		cout<<1;
		if((set1[2] == 'A' || set1[2] == 'B' || set1[2] == 'C') && (set2[2] == 'A' || set2[2] == 'B' || set2[2] == 'C'))
		{
			cout<<1;
		}
		else if((set1[2] == 'D' || set1[2] == 'F') && (set2[2] == 'D' || set2[2] == 'F'))
		{
			cout<<1;
		}
		else cout<<0;
	} 
	else cout<<"00";
	
	if(car1 == car2 && set1[0] == set2[0] && set1[1] == set2[1])
	{
		if(abs(set1[2] - set2[2]) == 1 && set1[2] != 'D' && set1[2] != 'F' && set2[2] != 'D' && set2[2] != 'F')
		{
			cout<<1;
		}
		else if((set1[2] == 'D' || set1[2] == 'F') && (set2[2] == 'D' || set2[2] == 'F'))
		{
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
