#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string o,p;
	cin>>a>>o>>b>>p;
	int c,d;
	c=(o[0]-'0')*10+(o[1]-'0');
	d=(p[0]-'0')*10+(p[1]-'0');
	char c1,d1;
	c1=o[2];
	d1=p[2];
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if((c1<='C' && d1<='C') || (c1>='D' && d1>='D')){
				cout<<1;
				if(abs(c1-d1)==1 && ((c1!='C' || d1!='D') && (c1!='D' || d1!='C'))){
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
