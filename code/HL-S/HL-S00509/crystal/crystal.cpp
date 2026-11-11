#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	sort(a+1,a+n+1);
	if(m>=c[n]) cout<<n;
	else{ 
		for(int i=1;i<=n;i++){
			if((m>=c[i] && m<c[i+1])){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}