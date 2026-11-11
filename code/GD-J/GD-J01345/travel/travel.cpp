#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a,b;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a[1]!=b[1]||a[0]!=b[0]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	n=a[2];
	m=b[2];
	n=n-64;
	m=m-64;
	if(n>m)swap(n,m);
	if((n<4&&m<4)||(m>3&&n>3)){
		cout<<1;
		if(m>3&&n>3)cout<<1;
		else if(m-1==n)cout<<1;
		else cout<<0;
	}
	else cout<<"00";
	return 0;
} 
