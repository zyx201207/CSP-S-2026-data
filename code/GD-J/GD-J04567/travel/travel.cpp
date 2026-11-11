#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a[4],b[4],x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<'\n';
		return 0;
	}else{
		cout<<1;
		a[1]=s1[0];
		a[2]=s1[1];
		x=s1[2];
		b[1]=s2[0];
		b[2]=s2[1];
		y=s2[2];
		if(a[1]!=b[1]||a[2]!=b[2]){
			cout<<"000"<<'\n';
			return 0;
		}else{
			cout<<1;
			if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
				cout<<"11";
				return 0;
			}
			if(x>='A'&&x<='C'&&y>='A'&&y<='C')cout<<1;
			else{
				cout<<"00"<<'\n';
				return 0;
			}
			if(x=='A'&&y=='C'||x=='C'&&y=='A')cout<<0<<'\n';
			else cout<<1<<'\n';
		}
	}
	return 0;
}
