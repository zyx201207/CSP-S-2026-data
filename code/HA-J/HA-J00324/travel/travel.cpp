#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
	int car;
	int pai;
	char l;
};
Node R,X;
bool a,b,c,d;
bool Pan_a(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			return true;
		}else return false;
	}else if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return true;
		}else return false;
	}
}//判断是否同一行 
bool Pan_b(char a,char b){
	if(a=='A'&&b=='B' || a=='B'&&b=='A')return true;
	if(a=='B'&&b=='C' || a=='C'&&b=='B')return true;
	if(a=='D'&&b=='F' || a=='F'&&b=='D')return true;
	return false;
}//判断是否相邻 
void Printf(bool a,bool b,bool c,bool d){
	if(a==true)printf("1");
	else printf("0");
	if(b==true)printf("1");
	else printf("0");
	if(c==true)printf("1");
	else printf("0");
	if(d==true)printf("1");
	else printf("0");
}//输出 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&R.car,&R.pai,&R.l,&X.car,&X.pai,&X.l);
	a=b=c=d=false;
	if(R.car==X.car){
		a=true;
		if(R.pai==X.pai){
			b=true;
			if(Pan_a(R.l,X.l)){
				c=true;
				if(Pan_b(R.l,X.l)){
					d=true;
				}
			}
		}
	}
	Printf(a,b,c,d);
	return 0;
}//本题我弟来了都会，只需要注意：1.D后面是F不是E 2.判断是一环扣一环，不是分开的 3.C和D之间并不相邻它们中间隔了个过道 
