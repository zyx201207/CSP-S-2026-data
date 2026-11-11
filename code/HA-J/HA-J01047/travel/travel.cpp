#include<bits\stdc++.h>
using namespace std;
int n,m,n1,m1;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>n1>>c>>m>>m1>>d;
	if(n==m){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n1==m1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n1==m1&&d>='D'&&c>='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c-d==1||d-c==1&&c!='C'&&d!='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
