#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
char b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		a1=a1*10+s1[i]-48;
		a2=a2*10+s2[i]-48;
	}
	b1=s1[2],b2=s2[2];
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if((b1<='C' and b2<='C') or (b1>='D' and b2>='D')){
				cout<<1;
				if(abs(b1-b2)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
