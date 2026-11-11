#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string a,b;
	cin>>x>>a>>y>>b;
	if(x!=y){
		cout<<"0000";
	}else{
		cout<<'1';
		int a1=0,b1=0;
		a1=(a[0]-'0')*10+a[1]-'0';
		b1=(b[0]-'0')*10+b[1]-'0';
		if(a1!=b1){
			cout<<"000";
		}else{
			cout<<1;
			int a2,b2;
			if(a[2]=='A'||a[2]=='B'||a[2]=='C')a2=1;
			else a2=0;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')b2=1;
			else b2=0;
			if(a2!=b2)cout<<"00";
			else{
				cout<<1;
				if(a2==0&&b2==0)cout<<1;
				else if(abs(int(a[2]-b[2]))==1)cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
} 
