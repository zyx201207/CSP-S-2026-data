#include<bits/stdc++.h>
using namespace std;
char co[105],so[105],ct[105],st[105];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>co[i];
	}
	for(int i=1;i<=3;i++){
		cin>>so[i];
	}
	for(int i=1;i<=2;i++){
		cin>>ct[i];
	}
	for(int i=1;i<=3;i++){
		cin>>st[i];
	}
    if(co[1]==ct[1]&&co[2]==ct[2]){
    	 cout<<"1";
    	 if(so[1]==st[1]&&so[2]==st[2]){
    	 	cout<<"1";
    	 	if((so[3]=='A'&&st[3]=='B')||(so[3]=='A'&&st[3]=='C')||(so[3]=='B'&&st[3]=='A')||(so[3]=='B'&&st[3]=='C')||(so[3]=='C'&&st[3]=='A')||(so[3]=='C'&&st[3]=='B')||(so[3]=='D'&&st[3]=='F')||(so[3]=='F'&&st[3]=='D')){
    	 		cout<<"1";
    	 		if((so[3]=='A'&&st[3]=='B')||(so[3]=='B'&&st[3]=='A')||(so[3]=='B'&&st[3]=='C')||(so[3]=='C'&&st[3]=='B')||(so[3]=='D'&&st[3]=='F')||(so[3]=='F'&&st[3]=='D')){
    	 		cout<<"1"; 
				 }else{
				 	cout<<"0";
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

