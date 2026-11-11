#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	int ant=4;
	if(a==b) {
		cout<<1;
		ant--;
		if(x[0]==y[0] && x[1]==y[1]) {
			cout<<1;
			ant--;
			int len_x=x.size(),len_y=y.size();
			if((x[len_x-1]<='C'&&y[len_y-1]<='C')||(x[len_x-1]>='D'&&y[len_y-1]>='D')) {
				cout<<1;
				ant--;
				char k_x=x[len_x-1],k_y=y[len_y-1];
				if((int)k_y-k_x==1) {
					cout<<1;
					ant--;
				}
			}
		}
	}
	for(int i=1;i<=ant;i++) {
		cout<<0;
	}
	return 0;
}
