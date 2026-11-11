#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a,c;
string b,d,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if( (b[2]>='D'&&d[2]<='C') || (d[2]>='D'&&b[2]<='C') ){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(b[2]-d[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}