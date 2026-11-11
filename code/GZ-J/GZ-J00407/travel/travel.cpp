//李杜文谦 GZ-J00407 清镇市广大实验学校
#include <bits/stdc++.h>
using namespace std;
string s,s1,c1,s2,c2;
int a[10][20],ax,ay,bx,by,cnt=1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')ax+=s1[i]-'0';
	}
	if(s1[2]=='A') ay=6;
	else if(s1[2]=='B') ay=5;
	else if(s1[2]=='C') ay=4;
	else if(s1[2]=='D') ay=2;
	else if(s1[2]=='F') ay=1;
	a[ax][ay]++;
	for(int i=0;i<s1.size();i++){
		if(s2[i]>='0'&&s2[i]<='9')bx+=s2[i]-'0';
	}
	if(s2[2]=='A') by=6;
	else if(s2[2]=='B') by=5;
	else if(s2[2]=='C') by=4;
	else if(s2[2]=='D') by=2;
	else if(s2[2]=='F') by=1;
	a[bx][by]++;
	if(ax==bx && (ay<3 && by<3 || ay>3 && by>3))cout<<"11";
	else if(ax==bx) cout<<10;
	else cout<<"00";
	if(a[ax+1][ay]==a[bx][by]||a[ax-1][ay]==a[bx][by]||a[ax][ay-1]==a[bx][by]||a[ax][ay+1]==a[bx][by]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
