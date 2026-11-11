//GZ-J00499 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,x,a,n1,n2;
	cin>>c>>s>>x>>a;
	n1=s[0]+s[1],n2=a[0]+a[1];
	if(c==x) {
		cout<<1;
		char q=s[2],w=a[2];
		if(n1==n2) {
			cout<<1;
			if((q>='D'&&w>='D')||(q<'D'&&w<'D')) {
				cout<<1;
				if(abs(int(q-w))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}

