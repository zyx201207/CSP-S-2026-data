#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2,ans = "0000";
	cin >> c1 >> s1 >> c2 >> s2;
	string r1,r2,x1,x2;
	r1 = s1[0],r1 += s1[1],r2 = s1[2];
	x1 = s2[0],x1 += s2[1],x2 = s2[2];
	
	if(c1 != c2) ans[0] = '0';
	else{
		ans[0] = '1';
		if(r1 != x1) ans[1] = '0';
		else{
			ans[1] = '1';
			int r,x;
			if(r2 == "A" || r2 == "B" || r2 == "C") r = 1;
			else r = 2;
			
			if(x2 == "A" || x2 == "B" || x2 == "C") x = 1;
			else x = 2;
			
			if(r != x) ans[2] = '0';
			else{
				ans[2] = '1';
				if(r == 2) ans[3] = '1';
				else{
					if((r2 == "A" && x2 == "C") || (r2 == "C" && x2 == "A"))
						ans[3] = '0';
					else ans[3] = '1';
				}
			}
		}
	}
	cout << ans;
	
	return 0;
}
