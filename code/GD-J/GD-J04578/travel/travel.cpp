#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int p1,p2,pl1,pl2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		p1+=int(a[i]-'0');
		p2+=int(c[i]-'0');
		if(b[i]>='0'&&b[i]<='9')pl1+=int(b[i]-'0');
		if(d[i]>='0'&&d[i]<='9')pl2+=int(d[i]-'0');
	}
	if(p1==p2){
		cout<<1;
		if(pl1==pl2){
			cout<<1;
			if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
				cout<<1;
				if(b[2]+1==d[2]||b[2]-1==d[2])cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
