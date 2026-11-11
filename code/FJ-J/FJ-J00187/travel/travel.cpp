#include <bits/stdc++.h>
using namespace std;
int c1, c2, e1, e2;
char s1, s2;
int main()
{
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin >> c1 >> e1 >> s1 >> c2 >> e2 >> s2;
	if(c1 == c2)
	{
		cout << 1;
		if(e1 == e2)
		{
			cout << 1;
			if((s1-'A' <= 2 && s2 - 'A' <= 2) || (s1-'A' >2&&s2-'A' > 2))
			{
				cout << 1;
				if(abs((s1-'A')-(s2-'A'))==1) cout << 1;
				else cout << 0;
			}
			else{
				cout << 0;
				cout << 0;
			}
		}
		else{
			cout << 0;
			cout << 0;
			cout << 0;
		}
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0; 
	}
	return 0;
}
