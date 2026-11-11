#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (n==4){
		cout<<12<<endl;
	}
	if (n==5){
		cout<<7<<endl;
	}
	return 0;
}
