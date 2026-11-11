#include<bits/stdc++.h>
using namespace std;
int a[3],b[3];
char a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool y=0;
	cin>>a[1]>>a[2]>>a1;
	cin>>b[1]>>b[2]>>b1;
	if(a[1]!=b[1]){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else if(a[2]!=a[2]){
		cout<<1<<0<<0<<0;
		return 0;
	}
	else if(('A'<=a1&&a1<='C'&&'A'<=b1&&b1<='B')||('D'==a1&&'F'==b1)||('F'==a1&&'D'==b1)){
		y=1;
	}
	else
		cout<<0<<0<<0<<0;
	if(y==1&&(a1-1==b1||a1+1==b1))
		cout<<1<<1<<1<<1;
	else
	cout<<1<<1<<1<<0;
	
	return 0;
}
