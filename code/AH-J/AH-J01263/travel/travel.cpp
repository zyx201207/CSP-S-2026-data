#include <bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy){
		if(sx[0]==sy[0]&&sx[1]==sy[1]){
			if(sx[2]>='D'&&sy[2]>='D'){
				if(sx[2]=='D'||sy[2]=='D') cout<<"1111";
				else if(sx[2]=='B'||sy[2]=='B') cout<<"1111";
				else cout<<"1110";
			}
			else if(sx[2]<='C'&&sy[2]<='C'){
				if(sx[2]=='D'||sy[2]=='D') cout<<"1111";
				else if(sx[2]=='B'||sy[2]=='B') cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
			
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
   return 0;
} 

