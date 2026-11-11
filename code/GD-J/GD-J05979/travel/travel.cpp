#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
string c1,s1,c2,s2;
int xiang1,xiang2;
int pai1,pai2;
char ce1,ce2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]-'0')!=0)xiang1+=(c1[0]-'0')*10;
	xiang1+=c1[1]-'0';
	if((c2[0]-'0')!=0)xiang2+=(c2[0]-'0')*10;
	xiang2+=c2[1]-'0';
	if(xiang1==xiang2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]-'0')!=0)pai1+=(s1[0]-'0')*10;
	pai1+=s1[1]-'0';
	if((s2[0]-'0')!=0)pai2+=(s2[0]-'0')*10;
	pai2+=s2[1]-'0';
	if(pai1==pai2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	ce1=s1[2];
	ce2=s2[2];
	if(ce1=='F'||ce1=='D'){
		if(ce2=='F'||ce2=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}else if(ce1=='A'||ce1=='B'||ce1=='C'){
		if(ce2=='A'||ce2=='B'||ce2=='C')cout<<"1";
		else{
			cout<<"00";
			return 0;
		}
	}
	if(ce1-1==ce2||ce1+1==ce2)cout<<"1";
	else cout<<"0";
	return 0;
}
