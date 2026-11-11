#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string che1,wei1,che2,wei2;
	cin >> che1 >> wei1 >> che2 >> wei2;
	if(che1==che2) 
	{
		cout << 1;
		//cout << "同车";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(wei1[0]==wei2[0]&&wei1[1]==wei2[1]) 
	{
		cout << 1;
		//cout << "同排";
		if(wei1[2]-'A'<=2&&wei2[2]-'A'<=2) 
		{
			cout << 1;
			//cout << "同边ABC";
			if(abs(wei1[2]-wei2[2])==1) cout << 1;
			else cout << "0";
			return 0;
		}
		if(wei1[2]-'A'>=3&&wei1[2]-'A'<=5&&wei2[2]-'A'>=3&&wei2[2]-'A'<=5) 
		{
			cout << 1;
			//cout << "同边DF";
			cout << 1;
			return 0;
		}
		cout << "00";
	}
	else
	{
		cout << "000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
