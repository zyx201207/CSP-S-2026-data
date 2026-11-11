#include<bits/stdc++.h>
using namespace std;
long long a[110000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn1=0;
	if(m>1){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j]>maxn1&&i!=j){
				maxn1=a[i]&a[j];
			}
		}
	}
	for(int i=1;i<=m-2;i++){
		if(maxn1&a[i]>maxn1){
			maxn1=maxn1&a[i];
		}
	}
}
	else{
		sort(a+1,a+n+1);
		maxn1=a[n];
	}
	cout<<maxn1;
}

