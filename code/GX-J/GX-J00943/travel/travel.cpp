#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,x,y,s,f;
	cin>>n>>x>>m>>y;
	if(n==m)cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
		}
	s=x[0]+x[1];
	f=y[0]+y[1];
	if(s==f)cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
		}
	s=x[2];
	f=y[2];
	if(s=="F"&&f=="D"){
		cout<<1<<1;
		return 0;
		}
	else if(s=="D"&&s=="F")cout<<1;
	else if(s=="A"&&(f=="B"||f=="C"))cout<<1;
	else if(s=="B"&&(f=="C"||f=="A")){
		cout<<1<<1;
		return 0;
		}
	else if(s=="C"&&(f=="A"||f=="B"))cout<<1;
	else cout<<0;
	if(s=="A"&&f=="B")cout<<1;
	else if(s=="C"&&f=="B")cout<<1;
	else cout<<0;
	return 0;
}
