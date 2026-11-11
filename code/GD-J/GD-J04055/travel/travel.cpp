#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void dyr(){
	string a,aa,b,bb;
	bool v=0,u=0,uu=0;
	cin>>a>>aa>>b>>bb;
	
	if(aa[2]>'C') u=1;
	if(bb[2]>'C') uu=1;
	
	if(a==b) cout<<1;
	else cout<<0;
	
	if(a==b&&aa[0]==bb[0]&&aa[1]==bb[1]){
		v=1;
		cout<<1;
	} 
	else cout<<0;
	
	if(a==b&&v==1&&u==uu) cout<<1;
	else cout<<0;
	
	if(a==b&&v==1&&u==uu&&abs(aa[2]-bb[2])==1) cout<<1;
	else cout<<0;
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	dyr();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
