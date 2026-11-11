#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&x[0]+x[1]==y[0]+y[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&x[0]+x[1]==y[0]+y[1]&&(x[2]+3!=y[2]||x[2]+2!=y[2]||x[2]+1!=y[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&x[0]+x[1]==y[0]+y[1]&&x[2]+1==y[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
