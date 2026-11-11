#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//小R车厢，座位，小X车厢，座位
	int a[]={},b[]={};
	 for(int i=0;i<18;i++){
		cin>>c1>>s1>>c2>>s2;
	 	if(c1[i]==c2[i]){
	 		cout<<"1";
		 }else{
		 	cout<<"0000";
		break;
		 }
	}
	for(int i=1;i<10;i++){
		 if(s1[i]>='0'&&s1[i]<='9'&&s2[i]>='0'&&s2[i]<='9'&&s1[i]==s2[i]){
		 cout<<"1";
		 }else{
		 	cout<<"0";
		 }
		if(s1[i]=='A'||'B'&&s2[i]=='A'||'B'){
			cout<<"1";
	}else{
		cout<<"0";
	}
	if(a[i]==b[i]&&s1[i]=='B'||'C'&&s2[i]=='B'||'C'){
			cout<<"1";
	}else{
		cout<<"0";
}
	if(a[i]==b[i]&&s1[i]=='D'||'F'&&s2[i]=='D'||'F'){
			cout<<"1";
	}else{
		cout<<"0";
	}
}
return 0;
}
