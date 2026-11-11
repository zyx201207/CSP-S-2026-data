#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[300099]={},b[300099]={};
	cin>>n>>m;
	int s=0,t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) s++;
		else t++;
	}
	cout<<s<<t;
	return 0;
}
