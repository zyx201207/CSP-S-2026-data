#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int t[250][250];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>r1>>r2>>x1>>x2;
	char a=r2[2],b=x2[2];
	if(a=='F') a='E';
	if(b=='F') b='E';
	
	if(r1==x1){
		cout<<1;
		if((r2[0]+r2[1])==(x2[0]+x2[1])){
			cout<<1;
			if(a>='A'&&a<='C'){
				if(b>='A'&&b<='C'){
					cout<<1;
					if(b==a+1||b==a-1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}
			if(a>='D'&&a<='E'){
				if(b>='D'&&b<='E'){
					cout<<1;
					if(b==a+1||b==a-1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
