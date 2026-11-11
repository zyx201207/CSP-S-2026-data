#include<bits/stdc++.h>
using namespace std;
//long long !!!!
const int N=5e5+320;
long long n,m,a[N];
long long s[N],maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long i=1,j=1;
	while(i<=n&&j<=n){
		while(a[j]*(j-i+1)-(s[j]-s[i-1])<=m&&j<=n){
			//cout<<i<<" "<<j<<" "<<a[j]*(j-i+1)<<" "<<s[j]-s[i-1]<<endl;
			maxn=max(maxn,j-i+1);
			j++;
		}
		while(a[j]*(j-i+1)-(s[j]-s[i-1])>m){
			i++;
		}
	}
	cout<<maxn;
	return 0;
}
