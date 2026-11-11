#include<bits/stdc++.h>
using namespace std;

long long m,n,ans=1;
long long a[1000000];

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=n;i>=1;i--){
		ans=a[i-1];
		break;
	}
	cout <<m<<ans<<n;
	return 0;
}
