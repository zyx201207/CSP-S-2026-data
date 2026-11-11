#include<bits/stdc++.h>
using namespace std;
int a1,a2,h1,h2,c1,c2; 
string s1,s2;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>a1>>s1>>a2>>s2;
	h1=int(s1[0]-'0')*10+int(s1[1]-'0');
	h2=int(s2[0]-'0')*10+int(s2[1]-'0');
	c1=int(s1[2]-'A')+1;
	c2=int(s2[2]-'A')+1;
	if(a1==a2){
		cout<<1;
		if(h1==h2){
			cout<<1;
			if(c1<=3&&c2<=3){
				cout<<1;
				if(abs(a1-a2)==1)cout<<1;
				else cout<<0;
			}
			else if(c1>=4&&c2>=4){
				cout<<1<<1;
			}else{
				cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
