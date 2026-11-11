#include<bits/stdc++.h>
using namespace std;
struct bh
{
	int cx;
	string zw;
};
bh a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1].cx>>a[1].zw>>a[2].cx>>a[2].zw;
	if(a[1].cx==a[2].cx){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a[1].zw[0]==a[2].zw[0]&&a[1].zw[1]==a[2].zw[1]){
		cout<<1;
		if(a[1].zw[2]=='E'||a[1].zw[2]=='D'&&){
			if(a[2].zw[2]=='E'||a[2].zw[2]=='D'){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		if(a[1].zw[2]=='A'){
			if(a[2].zw[2]=='B'||a[2].zw[2]=='C'){
				cout<<1;
			}
			else{
			cout<<0;
			}
		if(a[1].zw[2]=='B'){
			if(a[2].zw[2]=='C'||a[2].zw[2]=='A'){
				cout<<1;
			}
			else{
			cout<<0;
			}
		}
		if(a[1].zw[2]=='C'){
			if(a[2].zw[2]=='A'||a[2].zw[2]=='B'){
				cout<<1;
			}
			else{
			cout<<0;
			}
		}
	}
	else{
		cout<<0;
	}
	if(a[1].zw[2]=='D'&&a[2].zw[2]=='E'){
		cout<<1;
	}
	else if(((a[1].zw[2]=='B'&&a[2].zw[2]=='C')||(a[1].zw[2]=='C'&&a[2].zw[2]=='B'))||((a[1].zw[2]=='A'&&a[2].zw[2]=='B')||(a[1].zw[2]=='B'&&a[2].zw[2]=='A'))){
			cout<<1;
	}
	else{
		cout<<0;
	}
}
	else{
		cout<<0<<0<<0;
	}
}
