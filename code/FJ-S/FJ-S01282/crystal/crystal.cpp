#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n+1);
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n-1;i>1;i--){
		if(b[i]<=m&&b[i+1]>=m){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
}

