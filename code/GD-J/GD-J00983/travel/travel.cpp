#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>a.x>>s1>>b.x>>s2;
	a.y=(s1[0]-48)*10+(s1[1]-48),b.y=(s2[0]-48)*10+(s2[1]-48),a.z=s1[2]-64,b.z=s2[2]-64;
	if(a.x==b.x){
		cout<<"1";
		if(a.y==b.y){
			cout<<"1";
			if(a.z>=4&&a.z<=5&&b.z>=4&&b.z<=5){
				cout<<"11";
			}
			else if(a.z>=1&&a.z<=3&&b.z>=1&&b.z<=3){
				cout<<"1";
				if(abs(a.z-b.z)==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
