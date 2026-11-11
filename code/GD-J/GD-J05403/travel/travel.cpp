#include<bits/stdc++.h>
using namespace std;


string cara,carb,carda,cardb;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['D']=1;mp['F']=1;
	cin>>cara>>carda>>carb>>cardb;
	if(cara==carb)cout<<1;
	else {
		for(int i=1;i<=4;i++)cout<<0;
		return 0;
	}
	if(carda[0]==cardb[0] && carda[1]==cardb[1])cout<<1;
	else {
		for(int i=1;i<=3;i++)cout<<0;
		return 0;
	}
	if(mp[carda[2]]==mp[cardb[2]])cout<<1;
	else {
		for(int i=1;i<=2;i++)cout<<0;
		return 0;
	}
	if(abs(int(carda[2]-'0')-int(cardb[2]-'0'))==1)cout<<1;
	else cout<<0;
}
