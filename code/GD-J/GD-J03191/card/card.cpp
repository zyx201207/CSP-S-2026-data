#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],b[N]={0},c[N]={0},d[N];
int n,m,j=0,k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)j++
		else k++;
	}
	cout<<0<<n;
	return 0;
}
