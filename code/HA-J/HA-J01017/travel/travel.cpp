#include<bits/stdc++.h>
using namespace std;
int a=2;
int b[20];
int c[30];
char d[30];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i]>>d[i];
	}
	if(b[1]!=b[2]){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		if(c[1]!=c[2]){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if((d[1]=='D'&&d[2]=='F')||(d[1]=='F'&&d[2]=='D')){
				cout<<11;
				return 0;
			}else if((d[1]>='D'&&d[2]<'D')||(d[1]<'D'&&d[2]>='D')){
				cout<<"00";
				return 0;
			}else{
				cout<<1;
				if(int(d[1]-d[2])==1||int(d[2]-d[1])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
return 0;
}
