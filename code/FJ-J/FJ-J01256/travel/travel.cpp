#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	char t1=b[0]+b[1],t2=b[2];
	char k1=y[0]+y[1],k2=y[2];
	if(a==x){
		cout<<"1";
		if(t1==k1){
			cout<<"1";
			if(t2<='C'&&k2<='C'||t2>'C'&&k2>'C'){
				cout<<"1";
				int s1=t2-'A';
				int s2=k2-'A';
				int f=s1-s2;
				if(f==1||f==-1)cout<<"1";
				else cout<<"0";
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
