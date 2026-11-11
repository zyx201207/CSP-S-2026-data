#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
char x,y;
//Trick||Treat!
int main(){
	freopen("travel.in",stdin);
	freopen("travel.out",stdout);
	cin>>n>>a>>x;
	cin>>m>>b>>y;
	//cout<<n<<m<<a<<b<<x<<y;
	if(n==m)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'){
		cout<<1;
		if(x-y==1||y-x==1)
			cout<<1;
		else
			cout<<0;
	}
	else if(x=='F'&&y=='D'||x=='D'&&y=='F')
		cout<<11;
	else
		cout<<"00"; 
	
	return 0;
}
