#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string a,b;
	cin>>x>>a>>y>>b;
	string q,w;
	q=q+a[0]+a[1];
	w=w+b[0]+b[1];
	if(x==y){
		cout<<1;
		if(q==w){
			cout<<1;
			if((a[2]=='A'||a[2]=='B'||a[2]=='C'&&b[2]=='A'||b[2]=='B'||b[2]=='C')||(a[2]=='D'||a[2]=='f'&&b[2]=='D'||b[2]=='F')){
				cout<<1;
				if(abs(int(a[2])-int(b[2]))==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
