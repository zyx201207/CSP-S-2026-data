#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a=s1[0],b=s1[1],c=s2[0],d=s2[1];
		char g1=s1[2],g2=s2[2];
		if(a==c&&b==d){
			cout<<"1";
			if(((g1=='A')&&(g2=='B'||g2=='C'))||((g1=='B')&&(g2=='A'||g2=='C'))||((g1=='C')&&(g2=='A'||g2=='B'))||(g1=='D')&&(g2=='F')||(g1=='F')&&(g2=='D')){
				cout<<"1";
				if((g2-g1==1)||(g1-g2==1)){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
