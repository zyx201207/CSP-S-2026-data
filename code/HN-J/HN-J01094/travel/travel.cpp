#include<bits/stdc++.h>
using namespace std;

int a[2],b[2],n,m;
char p,q;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>p>>b[1]>>b[2]>>q;
	if(a[1]==b[1]){
		cout<<1;
		if(a[2]==b[2]){
			cout<<1;
			if(p<='C'&&q<='C'||p>='D'&&p>='D'){
				cout<<1;
				if(p-q==1||q-p==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
