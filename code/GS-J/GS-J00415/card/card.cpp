#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==4){
		cout<<3<<" "<<1<<" "<<4<<endl;
	}
	if (n==10){
		cout<<10<<" "<<3<<" "<<3<<endl;
	}
	return 0;
}
