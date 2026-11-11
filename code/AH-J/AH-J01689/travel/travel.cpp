#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		cout<<1;
		int x,y;
		x=(b[0]-48)*10+(b[1]-48);
		y=(d[0]-48)*10+(d[1]-48);
		if(x!=y) cout<<"000";
		else{
			cout<<1;
			int e=b[2]-64,f=d[2]-64;
			if(e>f) swap(e,f);
			if(e<=3&&f>3) cout<<"00";
			else{
				cout<<1;
				if(f-e==1||f-e==2&&f==6) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
