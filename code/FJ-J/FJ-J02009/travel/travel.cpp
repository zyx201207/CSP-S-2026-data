#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
string a,b,c,d;
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
				if(max(b[2],d[2])<='C'||min(b[2],d[2])>='D'){
					cout<<1;
					if(max(b[2],d[2])<='C'&&abs(b[2]-d[2])==1||min(b[2],d[2])>='D'){
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
}
