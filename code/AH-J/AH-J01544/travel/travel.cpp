#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,y1;
	string x2,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		cout<<1;
		int a,b;
		a=int(x2[0]-'0')*10+int(x2[1]-'0');
		b=int(y2[0]-'0')*10+int(y2[1]-'0');
		if(a==b){
			cout<<1;
			char c1=x2[2],c2=y2[2];
			if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D')){
				cout<<1;
				if((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')||abs(c1-c2)==1){
					cout<<1;
				}else{
					cout<<0;
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
