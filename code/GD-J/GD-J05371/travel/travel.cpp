#include<bits/stdc++.h>
using namespace std;
void solve(){
	int c1,c2,s1,s2;
	char p1,p2;
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if((p1=='A' && p2=='B') || (p1=='B' && p2=='A') ||
			   (p1=='B' && p2=='C') || (p1=='C' && p2=='B') ||
			   (p1=='D' && p2=='F') || (p1=='F' && p2=='D')) cout<<"11";
			else if((p1=='A' && p2=='C') || (p1=='C' && p2=='A'))  cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
