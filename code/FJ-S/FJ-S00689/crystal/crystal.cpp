#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q,b[500005],w,e;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	q+=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		q+=a[i];
	}
	for(long long i=1;i<=n;i++){
		b[i]=q/n;
	}
	q%=n;
	for(long long i=n;i>=n-q+1;i--){
		b[i]++;
	}
	for(long long i=n;i>=1;i--){
		b[i]-=a[i];
		if(b[i]>=0){
			e++;
		}
	}
	cout<<e;
 	return 0;
 }
