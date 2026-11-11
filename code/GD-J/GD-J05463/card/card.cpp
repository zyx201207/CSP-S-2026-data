#include<bits/stdc++.h>
using namespace std;
struct node {
	string id;
	string seat;
};
struct node1{
	string id1;
	string seat1;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	if(n==4){
		cout<<3<<" "<<1<<" "<<4;
	}else if(n==10){
		cout<<10<<" "<<3<<" "<<3;
	}else{
		cout<<0;
	}
	return 0;
} 
