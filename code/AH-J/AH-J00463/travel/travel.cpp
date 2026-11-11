#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,c3,c4;
	char a,b;
	cin>>c1>>c2>>a>>c3>>c4>>b;
	if(c1==c3){
		cout<<1;
		if(c2==c4){
			cout<<1;
			if(a<='C'&&b<='C'||a>='D'&&b>='D'){
				cout<<1;
				if(a-b==1||b-a==1)cout<<1;
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
