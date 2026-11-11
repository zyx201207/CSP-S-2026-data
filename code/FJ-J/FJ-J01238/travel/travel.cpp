#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int x,y;
char l,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}if(a==1){
		for(int i=1;i<s1.size();i++){
			if(s1[i]>='1'&&s1[i]<='9'){
				x=x*10+s1[i]-'0';
			}if(s1[i]>='A'&&s1[i]<='F'){
				l=s1[i];
			}if(s2[i]>='1'&&s2[i]<='9'){
				y=y*10+s2[i]-'0';
			}if(s2[i]>='A'&&s2[i]<='F'){
				r=s2[i];
			}
		}
		if(x==y){
			b=1;
		}if(b==1){
			if(l=='C'&&r<'C'){
				c=1;
			}else if(l=='D'&&r>'D'){
				c=1;
			}else if(r=='C'&&l<'C'){
				c=1;
			}else if(r=='D'&&l>'D'){
				c=1;
			}else if(l>'D'&&r>'D'){
				c=1;
			}else if(r<'C'&&l<'C'){
				c=1;
			}
			if(c==1){
				if(abs(l-r)==1){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
