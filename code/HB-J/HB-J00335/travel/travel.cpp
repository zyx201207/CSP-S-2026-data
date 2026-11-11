#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int flag1,flag2;


	cin >> c1 >> s1 >> c2 >> s2;

	if(s1[2] >= 'A' && s1[2] <= 'C')
		flag1 = 1;
	else
		flag1 = 2;
	if(s2[2] >= 'A' && s2[2] <= 'C')
		flag2 = 1;
	else
		flag2 = 2;


	if(c1[0] == c2[0] && c1[1] == c2[1])
	{
		cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            cout << 1;
            if(flag1 == flag2)
            {
                cout << 1;

                if(max(s1[2],s2[2]) - min(s1[2],s2[2]) == 2 && flag1 == flag2 && flag1 == true)
                {
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
            else
            {
                cout << "00";
            }
        }
        else
        {
            cout << "000";
        }
	}
	else
	{
		cout << "0000";
	}
}
