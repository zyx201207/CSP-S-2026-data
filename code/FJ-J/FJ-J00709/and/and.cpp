#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			a[i]&=a[i+1];
			a[i+1]=a[i];
		}
		cout<<a[n];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	
	return 0;
}
