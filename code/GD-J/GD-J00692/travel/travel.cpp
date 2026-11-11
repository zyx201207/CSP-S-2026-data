#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string ta,tb;
	ta=a2[0]+a2[1];
	tb=b2[0]+b2[1];
	if(ta==tb) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char ta1,tb1;
	ta1=a2[2];tb1=b2[2];
	mp['A']=1;mp['B']=2;mp['C']=3;mp['D']=5;mp['F']=6;
	if((mp[ta1]>=1&&mp[tb1]<=3)||(mp[ta1]>=5&&mp[tb1]<=6)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	if(abs(mp[ta1]-mp[tb1])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
