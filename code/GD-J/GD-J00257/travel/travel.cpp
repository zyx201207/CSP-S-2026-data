#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string b1,b2; 
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) {
		cout<<1;
		string x = b1.substr(0,2);
		string y = b2.substr(0,2);
		if(x==y) {
			cout<<1;
			x = b1.substr(2,1);
			y = b2.substr(2,1);
			int xxx,yxy;
			if(x=="A") xxx = 0;
			if(x=="B") xxx = 1;
			if(x=="C") xxx = 2;
			if(x=="D") xxx = 3;
			if(x=="F") xxx = 5;
			if(y=="A") yxy = 0;
			if(y=="B") yxy = 1;
			if(y=="C") yxy = 2;
			if(y=="D") yxy = 3;
			if(y=="F") yxy = 5;
			if(xxx<=2&&yxy<=2) {
				cout<<1;
				if(xxx>yxy) swap(xxx,yxy);
				if(xxx==0&&yxy==1){
					cout<<1;
				}
				else if(xxx==1&&yxy==2) cout<<1;
				else cout<<0;
			}
			else if(xxx>=3&&yxy>=3){
				cout<<1;
				if(xxx>yxy) swap(xxx,yxy);
				if(xxx==3&&yxy==5){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
