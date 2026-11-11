#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200350],Max=-1;
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<n;k++){
		long long kMax=0;
		for(int i=1;i<m;i++){
			long long Mmax=Max;
			for(int j=1;j<=n;j++){
				if(Mmax&a[j]>Max) kMax=Mmax&a[j];
			}
			Max=max(Max,kMax);
		}
	}
	cout<<Max;
	return 0;
}
