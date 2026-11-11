#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int rbox,xbox,rnum,xnum,rseat,xseat;
int tran(string s){
	return (s[0]-'0')*10+(s[1]-'0');
}
bool side(int x,int y){
	//0 1 2 3 4
	if(x>=0 and x<=2) return (y>=0 and y<=2);
	if(x>=3 and x<=4) return (y>=3 and y<=4);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	rbox=tran(c1),xbox=tran(c2);
	rnum=tran(s1),xnum=tran(s2);
	rseat=s1[2]-'A',xseat=s2[2]-'A';
	//同车厢 同排 同侧 相邻 
	if(rbox!=xbox) cout<<"0000";
	else{
		if(rnum!=xnum) cout<<"1000";
		else{
			if(side(rseat,xseat)==0)  cout<<"1100";
			else{
				if(abs(xseat-rseat)!=1) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
