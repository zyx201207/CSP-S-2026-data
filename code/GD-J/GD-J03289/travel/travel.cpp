#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	long long f,g,e[5]={};
	cin>>a>>c>>b>>d;
	if(a==b){
		e[1]=1;
		if(c[0]==d[0]){
			if(c[1]==d[1]){
				e[2]=1;
				if(c[2]=='A'||c[2]=='C'||c[2]=='B'){
					f=0;
				}else{
					f=1;
				}
				if(d[2]=='A'||d[2]=='C'||d[2]=='B'){
					g=0;
				}else{
					g=1;
				}
				if(f==g){
					e[3]=1;
					if(f==1){
						e[4]=1;
					}else{
						if(c[2]=='A'&&d[2]=='C'){
							f=0;
							e[4]=1;
						}
						if(c[2]=='C'&&d[2]=='A'){
							f=0;
						}else{
							e[4]=1;
						}
					}
				}
			}
		}
	}
	cout<<e[1]<<e[2]<<e[3]<<e[4];
	return 0;
}
