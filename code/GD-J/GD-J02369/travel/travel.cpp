#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool same(){
	return c1==c2;
}
bool sol(){
	return same()&&s1[0]==s2[0]&&s1[1]==s2[1];
}
void solve(char a1=s1[2],char a2=s2[2]){//是否相邻 
	if(same()&&sol()&&abs(a1-a2)==1) {
		if((a1=='C'&&a2=='D')||(a2=='C'&&a1=='D')) cout<<0;
		else cout<<1;
	}else cout<<0;
}
void solv(char a1=s1[2],char a2=s2[2]){//位于同一侧 
	if(same()&&sol()&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((a1<='C'&&a2<='C')||(a1>'C'&&a2>'C')) cout<<1;
		else cout<<0;
	}else cout<<0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;

	if(same()) cout<<1;
	else cout<<0;
	if(sol()) cout<<1;
	else cout<<0;
	solv();
	solve();
	return 0;
}
