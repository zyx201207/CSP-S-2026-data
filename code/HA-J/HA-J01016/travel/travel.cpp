#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char n,m;
	cin>>a>>b>>n>>c>>d>>m;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((n<='C'&&m<='C')||(n>'C'&&m>'C')){
				cout<<1;
				int f=m-n;
				if(f==1||f==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
