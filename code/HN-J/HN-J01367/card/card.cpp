#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
long long a[10000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
} 
