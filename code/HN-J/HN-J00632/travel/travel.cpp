#include <bits/stdc++.h>
using namespace std;
int c,s;
char a1,a2,b1,b2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a1>>b1>>c1>>s>>a2>>b2>>c2;
	int n1=int(a1-'0')*10+int(b1-'0');
	int m1=int(a2-'0')*10+int(b2-'0');
	int n2=int(c1-'A');
	int m2=int(c2-'A');
	if(c==s){
		cout<<1;
		if(n1==m1){
			cout<<1;
			if(n2>2&&m2>2||n2<3&&m2<3){
				cout<<1;
				if(abs(n2-m2)==1) cout<<1;
				else cout<<0;
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
