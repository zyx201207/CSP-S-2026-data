#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	cout<<m<<" "<<a[1]<<" "<<n;
}
