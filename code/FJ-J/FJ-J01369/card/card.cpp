#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			cout<<i<<" ";
		}
	}
	return 0;
}
