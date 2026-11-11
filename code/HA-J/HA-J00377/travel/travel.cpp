#include<bits/stdc++.h>
using namespace std;
int f(int x,int y){
	if(x>y)return x-y;
	else if(x<y)return y-x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else cout<<"0";
	if(f(s1,s2)==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
