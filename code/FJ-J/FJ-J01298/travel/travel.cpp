#include<bits/stdc++.h>
using namespace std;
int n,x;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>x>>b;
	if(n==x){
		cout<<1;
	}else{
		cout<<0000;
		return 0;
	}
	int z=(a[0]-'0')*10+(a[1]-'0'),g=(b[0]-'0')*10+(b[1]-'0');
	if(z==g){
		cout<<1;
	}else{
		cout<<1000;
		return 0;
	}
	bool flag1='A'<=a[2]&&a[2]<='C',flag2='A'<=b[2]&&'C'>=b[2];
	if(flag1==flag2){
		cout<<1;
	}else{
		cout<<1100;
		return 0;
	}
	if(a[2]+1==b[2]||a[2]-1==b[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
