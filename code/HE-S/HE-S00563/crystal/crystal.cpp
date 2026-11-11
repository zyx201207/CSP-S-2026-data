#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(m==0)cout<<0;
	else cout<<sum/n-1;
	return 0;
}
