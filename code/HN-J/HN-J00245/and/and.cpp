#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[1000005],maxx=-1;
int main(){
	//Trick||Treat!
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if((a[i]&a[j])>maxx&&i!=j){
				maxx=(a[i]&a[j]);
			}
		}
	}
	cout<<maxx;
	return 0;
}
