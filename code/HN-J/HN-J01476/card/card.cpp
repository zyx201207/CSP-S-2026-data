#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==a[i]){
			cout<<b[i];
		}
	}
} 

