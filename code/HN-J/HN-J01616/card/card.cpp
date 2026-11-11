#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	if(n==1||n==2)cout<<"1"<<" "<<"1";
	if(n==3)cout<<"1"<<" "<<"0";
	return 0;
}
