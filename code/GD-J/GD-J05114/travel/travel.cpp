//travel

#include <bits/stdc++.h>
using namespace std;

int coach1,coach2;
string seat1,seat2;

//相同车厢
bool coach(int coach1,int coach2)
{return coach1==coach2;}
//the same row
bool row(string seat1,string seat2) {
	if(!coach(coach1,coach2)) return false;
	string r1,r2;
	r1.push_back(seat1[0]);r1.push_back(seat1[1]);
	r2.push_back(seat2[0]);r2.push_back(seat2[1]);
	return r1==r2; 
}
//过道同一侧 
bool side(string seat1,string seat2) {
	if(!row(seat1,seat2)) return false;
	if((seat1[2]=='A'&&seat2[2]=='D')||(seat1[2]=='A'&&seat2[2]=='F')||(seat1[2]=='B'&&seat2[2]=='D')||(seat1[2]=='B'&&seat2[2]=='F')||(seat1[2]=='C'&&seat2[2]=='D')||(seat1[2]=='C'&&seat1[2]=='F'))
		return false;
	return true;
}
//相邻
bool neigh(string seat1,string seat2) {
	if(!side(seat1,seat2)) return false;
	if(seat2[2]-seat1[2]==1) return true;
	else return false;
}

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>coach1;
	cin>>seat1;
	cin>>coach2;
	cin>>seat2;
	
	if(seat1[2]>seat2[2]) swap(seat1,seat2);
	cout<<coach(coach1,coach2)<<row(seat1,seat2)<<side(seat1,seat2)<<neigh(seat1,seat2)<<endl;
	return 0;
}
