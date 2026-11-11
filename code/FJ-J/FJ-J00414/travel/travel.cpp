#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	int i;
	bool f=1;
    char man1[3],seat1[4],man2[3],seat2[4];
    cin>>man1>>seat1>>man2>>seat2;
    int a1=(man1[0]-'0')*10+man1[1]-'0';
    int a2=(man2[0]-'0')*10+man2[1]-'0';
    if (a1==a2){
    	cout<<"1";
	}
	else {
		cout<<"0";
	}
	f=1;
	for (i=0;i<=1;i++){
    	if (seat1[i]!=seat2[i]){
    		cout<<"0";
    		f=0;
    		break;
		}
	}
	if (f==1){
		cout<<"1";
	}
	f=1;
	if ((seat1[2]>='A' && seat1[2]<='C' && seat2[2]>='A' && seat2[2]<='C') || 
	(seat1[2]>='D' && seat1[2]<='F' && seat2[2]>='D' && seat2[2]<='F')){
		cout<<"1";
		if (abs(seat1[2]-seat2[2])==1){
			cout<<"1";
		}else {
			f=0;
		}
	}else {
		f=0;
		cout<<"0";
	}
	if (f==0){
		cout<<"0";
	}
	return 0;
}
