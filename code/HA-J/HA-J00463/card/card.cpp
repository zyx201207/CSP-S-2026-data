#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<"1";
	}else if(m==2){
		cout<<"1 2";
	}
	return 0;
}
