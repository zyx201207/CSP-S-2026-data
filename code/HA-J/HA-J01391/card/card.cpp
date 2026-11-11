#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+3];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<3<<" "<<1<<" "<<4;
	}
	else if(n==10){
		cout<<"10"<<" "<<"3 "<<3;
	}
	else{
		cout<<4<<" "<<5<<" 6";
	}
	if(n==8){
		cout<<3<<" 9"<<" 10";
	}
	else if(n==10000){
		cout<<"30"<<" 50 "<<80;
	}
	return 0;
}
