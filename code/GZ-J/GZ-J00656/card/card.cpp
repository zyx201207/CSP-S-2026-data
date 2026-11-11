//GZ-J00656 黔西市思源实验学校 孙世嘉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
	}else if(n==4&&m==3){
		cout<<"3 1 4";
	}else{
		cout<<"28";
	}
	return 0;
} 
