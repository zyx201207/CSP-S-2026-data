#include<bits/stdc++.h>
using namespace std;
string c1[10],c2[10],si[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++){
		cin>>c1[i];
	}//c1   
    for(int i=1;i<=3;i++){
    	cin>>si[i];
	}//s1
	for(int i=1;i<=2;i++){
		cin>>c2[i];
	}//c2
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}//s2
    if(c1[1]==c2[1]&&c1[2]==c2[2]){
	    cout<<1;
	}else cout<<0;//两张车票对应的座位是否在同一节车厢
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
	    if(si[1]==s2[1]&&si[2]==s2[2]){
		    cout<<1;
		}//两张车票对应的座位是否在同一节车厢的同一排
	}else cout<<0;
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
	    if(si[1]==s2[1]&&si[2]==s2[2]){
		    if((si[3]=='A'||si[3]=='B'||si[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){cout<<1;}
            else if((si[3]=='D'||si[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){cout<<1;}
		}
	}else cout<<0;//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	if(si[3]-'1'==s2[3]||si[3]+'1'==s2[3]){
	    if((si[3]=='C'&&s2[3]=='D')||(si[3]=='D'&&s2[3]=='C'))cout<<0;return 0;
	    else cout<<1;
    }//两张车票对应的座位是否相邻
	return 0;
}
