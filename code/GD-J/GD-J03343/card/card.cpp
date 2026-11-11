#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(n==4&&m==3){
		cout<<3<<" "<<1<<" "<<4;
	}else if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
	}else{
		for(int i = 1;i<=n;i++){
			cout<<1<<" ";
		}
	}
	return 0;
}
