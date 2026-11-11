#include <bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
			if(x==y){
				cout<<1;
			}//同一节车厢
			else{
				cout<<0;
			}
			if(a[0]==b[0]&&a[1]==b[1]){
				cout<<1;
			}
			else{
				cout<<0;
			}
			if((a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C') || a[2]=='D'&&b[2]=='F' || a[2]=='F'&&b[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
			if((a[0]==b[0]&&a[1]==b[1]) && ((a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C') || a[2]=='D'&&b[2]=='F' || a[2]=='F'&&b[2]=='D') && a[2]==b[2]+1||a[2]==b[2]-1||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
				cout<<1;
			}
			else{
				cout<<0;
			}
	return 0;
}
