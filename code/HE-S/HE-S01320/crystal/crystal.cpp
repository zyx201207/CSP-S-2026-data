#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long w=m,maxn=0;
		for(int j=1;j<=n;j++){
			if (a[i]>a[j]){
				b[j]=a[i]-a[j];
			}else{
				b[j]=a[j]-a[i];
			}
		}
		sort(b+1,b+n+1);
		for(int j=1;j<=n;j++){
			if (w>=b[j]){
				w-=b[j];
				maxn++;
			}else{
				break;
			}
		}
		if (maxn>sum){
			sum=maxn;
		}
	}
	cout<<sum;
	return 0;
}
//Oct31==Dec25?
