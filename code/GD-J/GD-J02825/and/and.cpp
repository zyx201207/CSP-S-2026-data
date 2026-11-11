#include <bits/stdc++.h>
using namespace std;
const int maxx=2e5+10;
int n,m,a[maxx],maxn=-100;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-m;j++){
			int sum=a[j];
			for(int t=j;t<=j+m-1;t++){
				sum=(sum&a[t]);
			}
			maxn=max(maxn,sum);	
		}
	}
	cout<<maxn;
}

