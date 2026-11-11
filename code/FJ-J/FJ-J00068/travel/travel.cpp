//T1 travel
#include<bits/stdc++.h>
using namespace std;
//map<char,int>{}
int rc,xc;
string rs,xs;
int ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	int rn=(rs[0]-48)*10+(rs[1]-48);
	int xn=(xs[0]-48)*10+(xs[1]-48);
	if(rc==xc)ans1=1;
	if(ans1&&rn==xn)ans2=1;
	if(ans2&&((rs[2]<='C'&&xs[2]<='C')||(rs[2]>='D'&&xs[2]>='D')))ans3=1;
	if(ans3&&(rs[2]+1==xs[2]||rs[2]-1==xs[2]))ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
