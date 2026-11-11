#include<bits/stdc++.h>
using namespace std;
string xcx,ycx,xzw,yzw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xcx>>xzw>>ycx>>yzw;
	string x,y;
	for(int i=0;i<xzw.size()-1;i++){
        x+=xzw[i];
	}
	for(int i=0;i<yzw.size()-1;i++){
        y+=yzw[i];
	}
	if(xcx==ycx){
		cout<<1;
		if(x==y){
			cout<<1;
			char a=xzw[2];
			char b=yzw[2];
			if(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F'){
				cout<<1;
			}else{
				cout<<0;
			}
			if(a=='A'&&b=='B'||a=='B'&&b=='A'||a=='B'&&b=='C'||a=='C'&&b=='B'||a=='D'&&b=='F'||a=='F'&&b=='D'){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;i
• 两张车票对应的座位是否在同一节车厢的同一排;i
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;i
• 两张车票对应的座位是否相邻。
*/
