#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,f;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		e=b[0]+b[1],f=d[0]+d[1];
		if(e==f){
			cout<<1;
			x=b[2],y=d[2];
			if((x>='A'&&x<='C'&&y>='A'&&y<='C')||(x>='D'&&x<='F'&&y>='D'&&y<='F')){
				cout<<1;
				if(x>y)swap(x,y);
				if(x=='A'&&y!='C'){
					cout<<1<<endl;
				}else{
					cout<<0<<endl;
				}
			}else{
				cout<<"00"<<endl;
			}
		}else{
			cout<<"000"<<endl;
		}
	}else{
		cout<<"0000"<<endl;
	}
	return 0;
}
