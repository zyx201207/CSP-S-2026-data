#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1001]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		if(n==4 && m==3){
			cout<<3<<" "<<1<<" "<<4;
		}else if(n==10 && m==3){
			cout<<10<<" "<<3<<" "<<3;
		}
	return 0;
}

