#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	char z1=s1[2],z2=s2[2];
	for(int i=0;i<3;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a=a*10+s1[i]-'0';
		} 
	}
	for(int i=0;i<3;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			b=b*10+s2[i]-'0';
		} 
	}
	bool n=0,m=0,x=0,y=0;
	if(c1==c2){
		n=1;
		if(a==b){
			m=1;
			if((z1>='A'&&z1<='C'&&z2>='A'&&z2<='C')||(z1>='D'&&z1<='F'&&z2>='D'&&z2<='F')){
				x=1;
				if(abs(int(z1)-int(z2))==1){
					y=1;
				}
			}
		}
	}
	cout<<n<<m<<x<<y;
	return 0;
}
