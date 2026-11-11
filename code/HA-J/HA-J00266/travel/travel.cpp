#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string trave1,G1,trave2,G2;
	cin>>trave1>>G1>>trave2>>G2;	
	string seat1="",seat2="";
	char sits,sitss;
	for(int i=0;i<3;i++){
		if(G1[i]>='A'&&G1[i]<='Z'){
			sits=G1[i];
		}else{
			seat1+=G1[i];
		}
		if(G2[i]>='A'&&G2[i]<='Z'){
			sitss=G2[i];
		}else{
			seat2+=G2[i];
		}
	}
	if(trave1==trave2){
		cout<<1;
		if(seat2==seat1){
			cout<<1;
			if(((sits>='A'&&sits<='C')&&(sitss>='A'&&sitss<='C'))||((sits>='D'&&sits<='F')&&(sitss>='D'&&sitss<='F'))){
				cout<<1;
				if(((sits=='A'&&sitss=='B')||(sits=='B'&&sitss=='C')||(sits=='D'&&sitss=='F'))||((sits=='B'&&sitss=='A')||(sits=='C'&&sitss=='B')||(sits=='F'&&sitss=='D'))){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
