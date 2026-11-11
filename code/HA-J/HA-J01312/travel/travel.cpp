#include<bits/stdc++.h>
using namespace std;
char s,s2;
int c,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s;
	cin>>c2>>s2;
	if(c==c2){
		cout<<1;
	}
	else 
		cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
