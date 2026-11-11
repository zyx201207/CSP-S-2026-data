#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char z,y;
int read(string x,bool f){
	int g=0;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			g*=10;
			g+=x[i]-'0';
		}
		else{
			if(f)
				if(x[i]=='F')
					y='E';
				else
					y=x[i];
			else
				if(x[i]=='F')
					z='E';
				else
					z=x[i];
		}
	}
	return g;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int a2=read(a,1),b2=read(c,1),a3=read(b,0),b3=read(d,0);
	if(a2!=a3){
		cout<<"0000";
	}
	else if(b2!=b3){
		cout<<"1000";
	}
	else if(!((y>='A'&&y<='C'&&z>='A'&&z<='C')||(y>='D'&&y<='E'&&z>='D'&&z<='E'))){
		cout<<"1100";
	}
	else if((y+1==z)||(y-1==z)){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	return 0;
}
