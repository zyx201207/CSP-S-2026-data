#include <bits/stdc++.h>
using namespace std;
int s1[2];
int s2[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1,c2,s1,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1==c2){
		cout<<1<<" ";
	}
	else{
		cout<<0<<" ";
	}
	return 0;
}