#include <bits/stdc++.h>
#include <string>
using  namespace  std;
int  main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string  c,s,cc,ss;
	cin>>c>>cc>>s>>ss;
	if(c==s){
		cout<<1;
		if(cc[0]==ss[0]&&cc[1]==ss[1]){
			cout<<1;
			if(cc[2]<='C'&&ss[2]<='C'){
				cout<<1;
				if(abs(cc[2]-ss[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else  if(cc[2]>='D'&&cc[2]>='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return  0;
} 
