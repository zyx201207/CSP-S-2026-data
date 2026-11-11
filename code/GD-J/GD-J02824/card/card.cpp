#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000005],cnt[5000005];
int main(){
	freopen("card.in.cpp","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<n-m;
	return 0;
}
