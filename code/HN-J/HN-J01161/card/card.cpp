#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cout<<a[i]<<"¡¡";
	return 0; 
}
