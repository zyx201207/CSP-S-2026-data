#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int e=max(m-n,m-n);
	for(int i=1;i<=e;i++){
		cout<<a[i+e];
	}
	return 0;
}
