#include <bits/stdc++.h>
using namespace std;
int r1,r2;
char r3;
int x1,x2;
char x3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>r3>>x1>>x2>>x3;
//	cout<<r1<<' '<<r2<<' '<<r3<<' '<<x1<<' '<<x2<<' '<<x3;
	if(r1==x1){
		cout<<1;
		if(r2==x2){
			cout<<1;
			if(r3 >= 'A' && r3 <= 'C' && x3 >= 'A' && x3 <= 'C'){
				cout<<1;
				char minn=min(r3,x3);
				char maxn=max(r3,x3);
				if(char(minn+1)==maxn)cout<<1;
				else cout<<0;
			}
			else if(r3 >= 'D' && r3 <= 'F' && x3 >= 'D' && x3 <= 'F'){
				cout<<1<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else {
		cout <<"0000";
	}
	
	return 0;
}
