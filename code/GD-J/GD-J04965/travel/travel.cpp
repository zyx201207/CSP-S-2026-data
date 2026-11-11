/*
1.两张车票对应的座位是否在同一节车厢;
2.两张车票对应的座位是否在同一节车厢的同一排；
3.两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
4.两张车票对应的座位是否相邻.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int fg=0;
	if(a==c){
		cout<<1;
		fg=1;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&fg){
		cout<<1;
		fg=1;
	}
	else {
		cout<<0;
	}
	int x=b[2]-'A'+1,y=d[2]-'A'+1;
	if(x<=3){
		if(y<=3&&fg){
			cout<<1;
		}
		else cout<<0;
	}
	else if(x>=4){
		if(y>=4&&fg){
			cout<<1;
		}
		else cout<<0;
	}
	if(x>=4){
		if(y>=4&&fg){
			cout<<1;
		}
		else cout<<0;
	}
	else if(x<=3){
		if(y<=3&&abs(y-x)==1&&fg){
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
