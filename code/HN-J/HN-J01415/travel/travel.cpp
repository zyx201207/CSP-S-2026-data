#include<bits/stdc++.h>
using namespace std;
string c,s,x,y,a[100][25];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>x>>y;
	if(c!=x){
		cout<<"0000";
	}else{
		cout<<1;
		int num=0,num1=0;
		for(int i=0;i<=1;i++){
			num=num*10+s[i]-'0';
			num1=num1*10+y[i]-'0'; 
		}
		if(num!=num1){
			cout<<"000";
		}else{
			cout<<1;
			if(y[2]<='C'&&s[2]<='C'||y[2]>'C'&&s[2]>'C'){
				cout<<1;
				int k=s[2]-y[2];
				k=abs(k);
				if(k>1){
					cout<<"0";
				}else{
					cout<<1; 
				}
			}else{
				cout<<"00";
			}
		}
	}
	
	return 0;
}
