#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005]={},tong[500005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]+=i;
	}
	for(int i=1;i<=n;i++){
		cout<<tong[i];
	}	
	return 0;
}
