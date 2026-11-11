#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
//	cerr<<c1<<" "<<c2<<endl;
	int l1,l2;
	string seat1,seat2;
	l1=stoi(s1.substr(0,2));
	l2=stoi(s2.substr(0,2));
//	cerr<<l1<<" "<<l2<<endl;
	seat1=s1.substr(2,1);
	seat2=s2.substr(2,1);
//	cerr<<seat1<<" "<<seat2<<endl;
	char seatNum1,seatNum2;
	seatNum1=seat1[0];
	seatNum2=seat2[0];
//	cerr<<seatNum1<<" "<<seatNum2<<endl;
	bool seatSide1,seatSide2; // ABCÊÇ0£¬DFÊÇ1 
	seatSide1=(seat1=="D"||seat1=="F");
	seatSide2=(seat2=="D"||seat2=="F");
//	cerr<<seatSide1<<" "<<seatSide2<<endl;
	bool sameCar=false,sameLine=false,sameSide=false,nextTo=false;
	if(c1==c2){
		sameCar=true;
	}
	if(sameCar&&l1==l2){
		sameLine=true;
	} 
	if(sameLine&&seatSide1==seatSide2){
		sameSide=true;
	}
//	cerr<<abs(seatNum1-seatNum2)<<endl;
	if(sameSide&&abs(seatNum1-seatNum2)==1){
		nextTo=true;
	}
	cout<<sameCar<<sameLine<<sameSide<<nextTo;
//	cerr<<sameCar<<sameLine<<sameSide<<nextTo;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
