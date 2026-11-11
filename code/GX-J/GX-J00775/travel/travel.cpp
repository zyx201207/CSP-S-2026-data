#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[8]={0},b[8]={0};
	int n,m;
	cin>>n;
	for(int i=0;i<8;i++) cin>>a[i];
	cin>>m;
	for(int j=0;j<8;j++) cin>>b[j];
	cout<<n;
	if(n==m && n!=1 && n!=16){
		cout<<1;
	}else{
		cout<<0;
	} 
	if(a[0]==b[0] && a[1]==b[1]){
	cout<<1;
	}else{
		cout<<0;
	}
	if(a[2]==a || a[2]==b || a[2]==c && b[2]==a || b[2]==b || b[2]==c){
		cout<<1;
	}else{
		cout<<0;
	}
	cout<<1;
	return 0;
}
