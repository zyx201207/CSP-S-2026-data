#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin)
	//freopen("travel.out","w",stdout)
	int n,m;
	char a[5],b[5];
	cin>>n>>a[1]>>a[2]>>a[3]>>m>>b[1]>>b[2]>>b[3];
	if(n==m&&n!=1&&n!=16){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(a[3]=='A'&&b[3]=='B'||a[3]=='B'&&b[3]=='A'||a[3]=='B'&&b[3]=='C'||a[3]=='C'&&b[3]=='B'||a[3]=='D'&&b[3]=='F'||a[3]=='F'&&b[3]=='D'){
		cout<<11;
	}else if(a[3]=='A'&&b[3]=='C'||a[3]=='C'&&b[3]=='A'){
		cout<<10;
	}else{
		cout<<0<<0;
	}
	return 0;
}
