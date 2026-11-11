#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,s=0;
	string c,d;
	char c2,d2;
	cin>>a>>c>>b>>d;
	if(a==b){
		s+=2;
	}else{
		cout<<0<<0<<0<<0;
	}
	if(s==2){
		for(int i=0;i<c.size()-1;i++){
			if(c[i]==d[i]) s++;
		}
		if(s==4){
			c2=c[2];d2=d[2];
			if(c2<='C'&&d2<='C'||c2>='D'&&d2>='D') s++;
			if((c2+1==d2||d2+1==c2)&&s==5) s++;
		}
	}
	if(s==6) cout<<1111;
	else if(s==5) cout<<1110;
	else if(s==4) cout<<1100;
	else if(s<4&&s!=0) cout<<1000;
}
