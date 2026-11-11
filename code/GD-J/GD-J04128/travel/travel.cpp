#include<bits/stdc++.h>
#define int long long
const int N=1e5+10;
const int INF=0x3f3f3f3f;
using namespace std; 
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//同一节车厢 
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	//同一排
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	//过道同一侧  相邻 
	if((int)s1[2]<=(int)'C'&&(int)s2[2]<=(int)'C'){
		cout<<1;
		if(abs((int)s1[2]-(int)s2[2])==1)cout<<"1";
		else cout<<"0";
	} 
	else if((int)s1[2]>=(int)'D'&&(int)s2[2]>=(int)'D'){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
}
