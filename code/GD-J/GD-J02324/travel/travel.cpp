#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel","w",stdin);
	freopen("travel","r",stdout);
	int n;
	char a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
	cout<<"0000";
		return 0; 
	}	
	if(a==c)
		n+=1000;
	if(b-d<0||d-b<0)
		n+=100;
	if(b-'B'>1||d-'B'>1)
		n+=10;
	if(b-'B'>0||d-'B'>0)
		n+=1;
	cout<<n;
	return 0;
}
