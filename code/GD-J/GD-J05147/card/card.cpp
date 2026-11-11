#include<bits/stdc++.h>
using namespace std;
int a[3000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout>>n>>' '>>m>>' '>>a[0];
	return 0;
}
