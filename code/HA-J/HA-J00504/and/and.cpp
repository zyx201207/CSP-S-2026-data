#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxx=-1,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long q=1<<n; 
	for(long long i=0;i<q;i++){
		int sum=0;
		long long z[200005]={0};
		for(int j=0;j<n;j++){
			if(i&1<<j){
				z[sum]=a[j];
				sum++;
			}
			if(sum>m){
				break;
			}
		}
		if(sum!=m){
			continue;
		}
		x=z[0];
		for(int j=1;j<m;j++){
			x=x&z[j];
		}
		maxx=max(maxx,x);
	}
	cout<<maxx;
	return 0;
}
