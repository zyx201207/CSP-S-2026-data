#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	int a,b,ok=1;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b)
	cout<<1;
	else{
		ok=0;
		cout<<0;
	}
	int x1=x[0]*10+x[1],y1=y[0]*10+y[1];
	if(x1==y1&&ok==1) cout<<1;
	else{
		ok=0;
		cout<<0;
	}
	char x2=x[2],y2=y[2];
	if((x2-'A'>2&&y2-'A'>2)||(x2-'A'<=2&&y2-'A'<=2)&&ok==1){
		cout<<1;
	}
	else{
		ok=0;
		cout<<0;
	}
	if(ok==1&&(x2+1==y2||y2+1==x2)) cout<<1;
	else cout<<0;
	return 0;
}

