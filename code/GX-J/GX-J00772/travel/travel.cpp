#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,bx,az,bz;
	cin>>ax>>az>>bx>>bz;
	int sa=0,sb=0,a=0,b=0;
	 a=az[2]-'A'+1;
	 b=bz[2]-'A'+1;
	 sa=(az[0]-'0')*10+az[1]-'0';
	 sb=(bz[0]-'0')*10+bz[1]-'0';
	if(ax==bx){
		 cout<<'1';
		 if(az[0]==bz[0]&&az[1]==bz[1]){
			cout<<'1';
			if(a>=4&&b>=4){
				cout<<'1';
			}
			else if(a<=3&&b<=3){
				cout<<'1';
			}
			else cout<<'0';
		 }
		 else cout<<"00";
	 }
	 else cout<<"000";
	 
	 if(az[0]==bz[0]&&az[1]==bz[1]&&(az[2]-1==bz[2]||az[2]+1==bz[2])&&((a<=3&&b<=3)||(a>=4&&b>=4))){
		cout<<'1';
	 }
	 else if((sa+1==sb||sa-1==sb)&&a==b){
		cout<<'1';
	 }
	 else cout<<'0';
	return 0;
}

