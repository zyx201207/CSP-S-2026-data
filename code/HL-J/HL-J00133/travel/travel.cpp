#include<bits/stdc++.h>
using namespace std;
int che1,che2;
char zuo1[4],zuo2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1;
	for(int i=1;i<=3;i++){
		cin>>zuo1[i];
	}
	cin>>che2;
	for(int i=1;i<=3;i++){
		cin>>zuo2[i];
	}
	if(che1==che2) cout<<"1";
		else{
			cout<<"0000";
			return 0;
		}
	if(zuo1[1]==zuo2[1]&&zuo1[2]==zuo2[2]){
		cout<<"1";
	}
		else
		{
			cout<<"000";
			return 0;
		}
	int panduan1=zuo1[3];
	int panduan2=zuo2[3];
	if((panduan1==65||panduan1==66||panduan1==67)&&(panduan2==65||panduan2==66||panduan2==67)){
		cout<<"1";
	}
	else if((panduan1==68||panduan1==70)&&(panduan2==68||panduan2==70)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(panduan1+1==panduan2) cout<<"1";
	else if(panduan1==panduan2+1) cout<<"1";
	else if(panduan1==68&&panduan2==70) cout<<"1"; 
	else cout<<"0";
	return 0;
}
