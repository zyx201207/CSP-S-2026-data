#include<bits/stdc++.h>
using namespace std;


int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	char cr[100],sr[100],cx[100],sx[100];
	scanf("%s",cr);
	scanf("%s",sr);
	scanf("%s",cx);
	scanf("%s",sx);
	
fclose(stdin); 
if(cr[0]==cx[0]&&cr[1]==cx[1]){
	cout<<1;
if(sr[0]==sx[0]&&sr[1]==sx[1]){
	cout<<1;
	char a=sr[2],b=sx[2];
	if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
		cout<<1;
	
	if(abs(a-b)==1){
		cout<<1;
	}
	else{
		cout<<0;
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

fclose(stdout); 	
	
return 0;	
} 
