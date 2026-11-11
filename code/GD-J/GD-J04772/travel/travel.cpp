#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,x,y;char ch1,ch2;
bool check(char c1,char c2){
	if(c1=='F'&&c2=='D')return true;
	if(c1=='D'&&c2=='F')return true;
	if(c1=='C'&&(c2=='B'||c2=='A'))return true;
	if(c1=='B'&&(c2=='C'||c2=='A'))return true;
	if(c1=='A'&&(c2=='B'||c2=='C'))return true;
	return false;
}bool check2(char c1,char c2){
	if(c1=='F'&&c2=='D')return true;
	if(c1=='D'&&c2=='F')return true;
	if(c1=='C'&&c2=='B')return true;
	if(c1=='B'&&(c2=='C'||c2=='A'))return true;
	if(c1=='A'&&c2=='B')return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>x>>ch1>>c2>>y>>ch2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<"1";
		if(x!=y)cout<<"000";
		else{
			cout<<"1";
			if(!check(ch1,ch2))cout<<"00";
			else{
				cout<<"1";
				cout<<check2(ch1,ch2);
			}
		}
	}
	return 0;
}
