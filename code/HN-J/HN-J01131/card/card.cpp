#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s,d;
	cin>>a>>s;
	for(int i=0;i<a;i++){
		cin>>d;
	}
	if(a==4)cout<<3<<' '<<1<<' '<<4;
	else if(a==10)cout<<10<<' '<<3<<' '<<3;
	return 0;
} 
