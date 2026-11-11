#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;//ÅÅÊý 
	int c1,c2;//³µÏá 
	char z1,z2;
	cin>>c1>>s1>>z1>>c2>>s2>>z2;
	if(c1!=c2)cout<<"0000";
	else{
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(((z1=='A'||z1=='B'||z1=='C')&&(z2=='A'||z2=='B'||z2=='C'))||((z1=='D'||z1=='F')&&(z2=='D'||z2=='F'))){
				cout<<1;
				if(z1+1==z2||z1-1==z2||z2+1==z1||z2-1==z1){
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
	}return 0;
}
