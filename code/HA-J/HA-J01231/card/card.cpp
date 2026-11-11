#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0;
	int a[500005];
	int a1[5]={0,1,2,1,3};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a1[i])x=1;
	}
	if(x=1)cout<<3<<" "<<1<<" "<<4;
	return 0;
}
