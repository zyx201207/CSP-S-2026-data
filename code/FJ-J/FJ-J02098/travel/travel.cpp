#include <bits/stdc++.h>
using namespace std;
int r,x,ans1,ans2,ans3,ans4;
string seatR,seatX;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>seatR>>x>>seatX;
	if(r==x){
		ans1=1;
		if(seatR[0]==seatX[0] && seatR[1]==seatX[1]){
			ans2=1;
			bool a=seatR[2]>'C',b=seatX[2]>'C';
			if(a==b){
				ans3=1;
				if((a && b)|| abs(seatR[2]-seatX[2])==1) ans4=1;
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
