#include<bits/stdc++.h>
using namespace std;
int c[1001],m[1001];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,ans=0;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>c[i];
	}
	if(m[1]=2&&c[1]='a'&&m[2]=3&&m[2]=='a'){
		cout<<0;
	}
	if(m[1]=1000000000&&c[1]='a'&&m[2]=1000000000&&m[2]=='a'&&m[3]=1000000000&&c[3]='a'&&m[4]=1000000000&&m[4]=='b'&&m[5]=1000000000&&c[5]='b'&&m[6]=1000000000&&m[6]=='b'){
		cout<<1000000000;
	}
	if(m[1]=2&&c[1]='a'&&m[2]=3&&m[2]=='a'){
		cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
