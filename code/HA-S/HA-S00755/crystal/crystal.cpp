#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
long long a[500005],b[500005],z[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		if (i!=1){
			b[i-1]=a[i]-a[i-1];
			z[i-1]=z[i-2]+(i-1)*b[i-1];
			if (z[i-1]<=m&&i>sum){
				sum=i;
			}
		}
	}
	/*for (int i=1;i<=n;i++){
		if (i!=1){
			cout<<z[i-1]<<" ";
		}
		cout<<endl;
	}*/
	cout<<sum;
	return 0;
}
