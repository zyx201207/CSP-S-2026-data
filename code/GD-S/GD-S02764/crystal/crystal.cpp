#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long i=1;
	while(i<=n){

	cin>>a[i];
	i++;
}


	sort(a+1,a+1+n);

	long long M=1;
	for(long long i=1;i<=n;i++){
		long long t=m;
		long long id=i;
		id--;
		long long ans=1;
		while(t>=0 && id>0){
			if((a[i]-a[id])<=t){
				ans++;
				t-=(a[i]-a[id]);
}
			id--;

		}

		M=max(M,ans);
	}
	cout<<M;

	return 0;

}
