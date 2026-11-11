#include<bits/stdc++.h>
using namespace std;
int a[30];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ys=0,ts=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1) ys++;
		else ts++;
	}
	cout<<ys<<' '<<ts;
	return 0;
}
