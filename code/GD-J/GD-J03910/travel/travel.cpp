#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int b1=a1-'A'+1,b2=a2-'A'+1;
	if((b1<=3 && b2<=3) || (b1>=4 && b2>=4)){
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
