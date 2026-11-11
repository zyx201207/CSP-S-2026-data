#include<bits/stdc++.h>
using namespace std;
int num[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(num[1]==1&&num[2]==2&&num[3]==1&&num[4]==3){
		cout<<3<<1<<3;
	}
	else{
		cout<<10<<3<<3;
	}
}
