#include<bits/stdc++.h>

using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cher,chex,zuor,zuox;
	int r,x,c,f;
	c='C';
	f='F';
	cin>>cher>>zuor>>chex>>zuox;
	r=zuor[2];
	x=zuox[2];
	
	if(cher!=chex)cout<<"0000";
	else if(zuor[1]!=zuox[1]||zuor[0]!=zuox[0])
	cout<<"1000";
	else if(!(r<=c&&x<=c||r<=f&&r>c&&x<=f&&x>c))
	cout<<"1100";
	else if(r-1!=x&&r+1!=x)cout<<"1110";
	else cout<<"1111"; 
	return 0; 
}
