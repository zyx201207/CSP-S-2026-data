#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s1=s2){
		cout<<111;
	}
	fclose("travel.in");
	fclose("travel.out");
	return 0;
}
 
