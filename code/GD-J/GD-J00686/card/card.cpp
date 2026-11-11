#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<' ';
			}
		}
	}
	return 0;
}
