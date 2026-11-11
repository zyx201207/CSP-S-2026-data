#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x1,y1,x2,y2;
	char z1,z2;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	if(x1==x2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}if(y1==y2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}if(z1<='C' && z2<='C' || z1>'C' && z2>'C'){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}if(z1-z2==1 || z2-z1==1){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
