#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		if(i==1)cout<<n<<" ";
		else if(i==2)cout<<m<<" ";
		else if(i==3)cout<<a[1]<<" ";
		else cout<<i<<" ";
	}
}
