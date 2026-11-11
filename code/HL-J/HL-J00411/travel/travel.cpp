#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char b1,b2;
int a1,a2;
int c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
		for(int i=0;i<s1.size();i++){
    	if(s1[i]>='0'&&s1[i]<='9'){
    		a1*=10;
    		a1=a1+s1[i]-48;
		}
    	else b1=s1[i];
    	if(s2[i]>='0'&&s2[i]<='9'){
    		a2*=10;
    		a2=a2+s2[i]-48;
		}
    	else b2=s2[i];
	} 
		if(a1==a2) {
			c1=b1-65+1;
			c2=b2-65+1;
				if(c1>=1&&c1<=3&&c2>=1&&c2<=3||c1>=4&&c1<=5&&c2>=4&&c2<=5){
					if(c1>=4&&c1<=5&&c2>=4&&c2<=5) cout<<1111;
					else if(abs(c1-c2)==1) cout<<1111;
					else cout<<1110;
				}
				else cout<<1100;
		}
		else cout<<1000;
	}
    else {
    	cout<<0<<0<<0<<0;

	} 
}
