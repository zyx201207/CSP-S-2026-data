#include<bits/stdc++.h>
using namespace std; 
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int  c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
     int a=(s1[0]-'0')*10+s1[1]-'0';
	 int b=(s2[0]-'0')*10+s2[1]-'0';
	 char a1=s1[2], b1=s2[2];
	 if(c1==c2){
	 	cout<<1;
	 	if(a==b){
	 		cout<<1;
	 		if(a1>='A' and a1<='C' and  b1>='A' and b1<='C'){
	 			cout<<1;
	 			int cha=a1-b1;
	 			if(cha==1 or cha==-1){
	 				cout<<1;
	 			}else{
	 				cout<<"0";
	 			}
	 		}else if(a1=='D' or a1=='F' and b1=='D' or b1=='F'){
	 			cout<<"11";
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
