#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50001],c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)
		//cout<<a[i]<<" ";
	int psc=n/2;
	if(n%2==1)
		psc++;
	for(int i=psc+1;i<=n;i++){
		if(a[i]!=a[psc])
			break;
		psc++;
	}
	for(int i=psc;i>=1;i--){
		while(a[i]!=a[psc]){
			if(a[i]+m<a[psc]){
				cout<<c;
				return 0;
			}
			a[i]++;
			m--;
			//cout<<c<<" ";
		}
		c++;
	}
	while(m>=a[psc+1]-c && c<n){
		c++;
		m-=c;
		psc++;
	}
	cout<<c;
	return 0;
}
