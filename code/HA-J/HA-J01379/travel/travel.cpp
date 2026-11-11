#include <bits/stdc++.h>
using namespace std;
freopen ("travel.in","r",stdin);
freopen ("travel.out","w",stdout);
int main()
{
	string c1,s1,c2,s2;
	int cnt = 4;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
	{
		cout << 1;
		cnt--;
		if(s1[0] = s2[0] && s1[1] == s2[1]){
			cout << 1;
			cnt--;
			if(s1[2] >= 'D' && s2[2] >= 'D' || s1[2] <= 'C' && s2[2] <= 'C'){
			
			    cout << 1;
			    cnt--;
		    }
			if(s1[2] == 'D'&&s2[2] == 'F'){
			    cout << 1;
			    cnt--;
				
		    }
		    	
		}
    }
    for (int i = cnt;i > 0;i--){
    	cout << 0;
	}
	return 0;
}
