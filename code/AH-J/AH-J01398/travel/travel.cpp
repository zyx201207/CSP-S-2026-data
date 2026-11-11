#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int f=4;
	cin>>a>>b>>c>>d;
	if (a==c) {//同一节车厢 
		cout<<1;f--;
		if (b[0]==d[0]&&b[1]==d[1]) {//位于同一排 
			cout<<1;f--;
			if (b[2]<='C'&&d[2]<='C') {//位于同一侧 
				cout<<1;f--;
				if (abs(b[2]-d[2])==1) {//相邻 
					cout<<1; f--;
				}
			}
			if (b[2]>='D'&&d[2]>='D') {
				cout<<1;f--;
				if (abs(b[2]-d[2])==1) {
					cout<<1; f--;
				}
			}
		}
	}
	while (f--) {
		cout<<0;
	}
	return 0;
}

