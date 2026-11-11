#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,st1,st2;
int ans1,ans2,ans3,ans4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>st1>>c2>>st2;
	if(c1==c2)ans1=1;
	if(ans1&&st1.substr(0,2)==st2.substr(0,2))ans2=1;
	if(ans2&&((st1[2]>='D'&&st2[2]>='D')||(st1[2]<='C'&&st2[2]<='C')))ans3=1;
	if(ans3&&abs(st1[2]-st2[2])==1)ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0; 
}
