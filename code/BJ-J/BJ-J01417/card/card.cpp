#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[500001],b[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=1;
	for(int j=n;j>=1;j--){
		for(int i=1;i<=1;i++){
			b[d]=a[j];
			d++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
}
