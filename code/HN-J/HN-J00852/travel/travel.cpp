#include <bits/stdc++.h>
using namespace std;
int a[10];
int get(char c){
	return c-'A'+1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=6;
	a[6]=7;
	int c1,c2,s1x,s2x;
	char s1y,s2y;
	scanf("%d %d%c %d %d%c",&c1,&s1x,&s1y,&c2,&s2x,&s2y);
	if(c1!=c2){
		cout << "0000";
	}else if(s1x!=s2x){
		cout << "1000";
	}else if(abs(a[get(s1y)]-a[get(s2y)])>2){
		cout << "1100";
	}else if(abs(a[get(s1y)]-a[get(s2y)])!=1){
		cout << "1110";
	}else{
		cout << "1111";
	}
}
