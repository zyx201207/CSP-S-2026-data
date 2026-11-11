#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c1>>c>>d>>c2;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if((c1>='A'&&c1<='C'&&c2<='C'&&c2>='A')||(c1>='D'&&c2>='D'&&c1<='F'&&c2<='F')){
				cout<<"1";
				if(c1-c2==1||c1-c2==-1||(c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')){
					cout<<"1";
				}else{
					cout<<"0";
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}
