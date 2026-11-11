#include<bits/stdc++.h>
using namespace std;
int a[5000005],n,m,i;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n<<m<<m+n;
}
