#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int j=2,k=1;
	while(j<=n){
		if((j-k)*a[j]-(s[j-1]-s[k-1])<=m){
			j++;
		}else{
			k++;
			j++;
		}
	}
	cout<<j-k;
	return 0;
}
