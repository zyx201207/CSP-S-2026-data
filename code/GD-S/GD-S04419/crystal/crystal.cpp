#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=1e5*5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int maxn=1;
	for (int i=1;i<=n;i++){
		long long chance=m;int crystal=1;
		for (int j=i-1;j>=1;j--){
			if (chance>=(a[i]-a[j])){
				chance-=(a[i]-a[j]);
				crystal++;
			}
			else{
				break;
			}
		}
		maxn=max(crystal,maxn);
	}
	cout<<maxn<<endl;
	return 0;
}
