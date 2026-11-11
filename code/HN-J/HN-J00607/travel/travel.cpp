#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char b1,d1;
bool vis(char b1,char d1){
	int b2=int(b1-'A'+1),d2=int(d1-'A'+1);
	if(b2<=3&&d2<=3) return 1;
	if(b2>3&&d2>3) return 1;
	return 0;
}
bool vis1(){
	int b2=int(b1-'A'+1),d2=int(d1-'A'+1);
	if(b2<=3&&d2<=3){
		if(b2+1==d2||b2-1==d2) return 1;
		return 0;
	}
	if(b2>3&&d2>3) return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>b>>b1;
	cin>>c;
	cin>>d>>d1;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b==d) cout<<1;
	else cout<<0;
	if(a==c&&b==d&&vis(b1,d1)) cout<<1;
	else cout<<0;
	if(a==c&&(b==d&&vis1())||((b+1==c||b-1==c)&&b1==d1)) cout<<1;
	else cout<<0;
	
	return 0;
} 
