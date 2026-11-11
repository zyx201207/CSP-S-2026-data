#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
	cin>>a1>>a2>>a3>>a4>>a5>>b1>>b2>>b3>>b4>>b5;
	if(a1==b1&&a2==b2){
		cout<<1;
		if(a3==b3&&a4==b4){
			cout<<1;
			if(a5<'D'&&b5<'D'){
				cout<<1;
				if((int(a5)+1==int(b5))||(int(b5)+1==int(a5)))cout<<1;
				else cout<<0;
			}
			else if(a5>='D'&&b5>='D'){
				cout<<1;
				if((a5=='D'&&b5=='F')||(b5=='D'&&a5=='F'))cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
 return 0;
}
