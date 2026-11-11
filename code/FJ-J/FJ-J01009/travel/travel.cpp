#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//#define int long long
signed main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	int ans1,ans2,ans3,ans4;
	if(c1==c2){
		ans1=1;
	}else{
		ans1=0;
	}
	if(ans1&&s1.substr(0,2)==s2.substr(0,2)){
		ans2=1;
	}else{
		ans2=0;
	}
	if(ans2&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))){
		ans3=1;
	}else{
		ans3=0;
	}
	if(ans3&&abs(s1[2]-s2[2])==1){
		ans4=1;
	}else{
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4<<endl;
	return 0;
} 
