#include<bits/stdc++.h>
#define qwq return 0;
#define int long long
using namespace std;
int a,b,x,y,f1,f2,f3,f4;
char c1,c2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>c1;
	cin>>y>>b>>c2;
	if(x==y) f1=1;
	if(a==b&&f1) f2=1;
	if(f2&&x!=1&&x!=16){
		if(c1-'A'<3&&c2-'A'<3) f3=1;
		if(c1-'A'>2&&c2-'A'>2) f3=1;
	} 
	if(c2-c1==1&&f2&&f3) f4=1;
	cout<<f1<<f2<<f3<<f4;
	qwq
}
//Trick||Treat!
//RP++
//Ô¤¼Æ100pts 
