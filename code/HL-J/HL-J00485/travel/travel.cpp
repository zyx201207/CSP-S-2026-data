#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool ans1=(c1==c2),ans2=0,ans3=0,ans4=0;
	if(ans1){
		if((s1[0]==s2[0])&&(s1[1]==s2[1]))ans2=1;
	}
	if(ans2){
		if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))ans3=1;
	}
	if(ans3){
		if(abs(s1[2]-s2[2])==1)ans4=1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}

