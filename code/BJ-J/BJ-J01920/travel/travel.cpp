#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h;
	char x,y;
	scanf("%c%c %c%c%c %c%c %c%c%c",&a,&b,&c,&d,&x,&e,&f,&g,&h,&y);
	//cout<<d;
	if(a==e&&b==f){
		cout<<"1";
		if(c==g&&d==h){
			cout<<"1";
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				cout<<"1";
				if(x==y+1||y==x+1){
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
