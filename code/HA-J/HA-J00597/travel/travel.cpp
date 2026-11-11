#include<bits/stdc++.h>
using namespace std;
int c1,c2,l1,l2;char h1,h2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&l1,&h1,&c2,&l2,&h2);
	if(c1==c2){
		if(l1==l2){
			if(h1>='D' && h2>='D')	cout<<"1111";
			else if(h1<='C' && h2<='C'){
				if(h1=='B' || h2=='B')	cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
