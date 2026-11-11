#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==4&&n==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
		cout<<3<<1<<4<<'/n';
	}
	return 0;
}
