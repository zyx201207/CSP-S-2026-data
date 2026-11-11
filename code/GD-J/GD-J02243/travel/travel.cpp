#include<bits/stdc++.h>
using namespace std;
int c,s;
string cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>cc>>s>>ss;
	if(c==s){
		cout<<1;
		if(cc[0]==ss[0]&&cc[1]==ss[1]){
			cout<<1;
			if((cc[2]>='D'&&ss[2]>='D')||(cc[2]<'D'&&ss[2]<'D')){
				cout<<1;
				if((cc[2]>='D'&&ss[2]>='D')||(cc[2]<'D'&&ss[2]<'D'&&abs(cc[2]-ss[2])==1)){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
