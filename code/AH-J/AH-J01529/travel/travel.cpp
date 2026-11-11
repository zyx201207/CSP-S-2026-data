#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int f[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x!=y){
		cout<<"0000\n";
		return 0;
	}
	cout<<1;
	if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"000\n";
		return 0;
	}
	cout<<1;
	if(!((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C'))){
		cout<<"00\n";
		return 0;
	}
	cout<<1;
	f[a[2]-'A']++;
	f[b[2]-'A']++;
	if((f[0]&&f[1])||(f[1]&&f[2])||(f[3]&&f[5])){
		cout<<1<<"\n";
	}else cout<<0<<"\n";
	return 0;
}
//Trick||Treat!
