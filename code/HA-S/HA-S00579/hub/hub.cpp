#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<(i&c)<<endl;
		if(c>7) c--;
	}
return 0;}
