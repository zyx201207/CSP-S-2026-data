#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=c1[0]*10+c1[1],a2=c2[0]*10+c2[1];
	if(a1==a2)cout<<1;
	else{
		cout<<"0000";
		return 0; 
	}
	int b1=s1[0]*10+s1[1],b2=s2[0]*10+s2[1];
	if(b1==b2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int d1=s1[2]-'A'+1,d2=s2[2]-'A'+1;
	if((d1<=3&&d2<=3)||(d1>3&&d2>3))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(d1-d2==1||d2-d1==1)cout<<1;
	else cout<<0;
	return 0;
}
