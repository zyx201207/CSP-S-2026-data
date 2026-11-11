#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
char cc1,cc2;
int ss1,ss2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	ss1=(s1[0]-'0')*10+s1[1]-'0';
	ss2=(s2[0]-'0')*10+s2[1]-'0';
	cc1=s1[2],cc2=s2[2];
	if(ss1!=ss2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(cc1>cc2) swap(cc1,cc2);
	if((cc1=='A'||cc1=='B'||cc1=='C')&&(cc2=='D'||cc2=='F')){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(cc2-cc1==1) cout<<"1";
	else cout<<"0";
	return 0;
}
