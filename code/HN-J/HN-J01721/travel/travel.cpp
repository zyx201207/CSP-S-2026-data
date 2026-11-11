#include<bits/stdc++.h>
using namespace std;
int xcx,xp,xc;
int ycx,yp,yc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	int x1l=x1.size(),x2l=x2.size();
	int y1l=y1.size(),y2l=y2.size();
	for(int i=0;i<x1l;i++){
		xcx=xcx*10+(x1[i]-'0');
		ycx=ycx*10+(y1[i]-'0');
	}
	for(int i=0;i<x2l-1;i++){
		xp=xp*10+(x2[i]-'0');
		yp=yp*10+(y2[i]-'0');
	}
	if(x2[x2l-1]=='A' or x2[x2l-1]=='B' or x2[x2l-1]=='C'){
		xc=1;
	}
	if(y2[y2l-1]=='A' or y2[y2l-1]=='B' or y2[y2l-1]=='C'){
		yc=1;
	}
	if(xcx==ycx){
		cout<<"1";
		if(xp==yp){
			cout<<"1";
			if(xc==yc){
				cout<<"1";
				if(xc==0){
					cout<<"1";
				}
				else{
					if(abs((x2[x2l-1]-'A')-(y2[y2l-1]-'A'))==1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
