#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sce1,sz1,sce2,sz2;
	cin>>sce1>>sz1>>sce2>>sz2;
	if(sce1==sce2){
		cout<<1;
		if(sz1[0]==sz2[0]&&sz1[1]==sz2[1]){
			cout<<1;
			if(((sz1[2]=='A'||sz1[2]=='B'||sz1[2]=='C')&&(sz2[2]=='A'||sz2[2]=='B'||sz2[2]=='C'))||
			((sz1[2]=='D'||sz1[2]=='F')&&(sz2[2]=='D'||sz2[2]=='F'))){
				cout<<1;
				if((sz1[2]=='A'&&sz2[2]=='B')||(sz1[2]=='B'&&sz2[2]=='A')||(sz1[2]=='B'&&sz2[2]=='C')
				||(sz1[2]=='C'&&sz2[2]=='B')||(sz1[2]=='D'&&sz2[2]=='F')||(sz1[2]=='F'&&sz2[2]=='D')){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
