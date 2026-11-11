#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2100000],b[2100000],minn=INT_MAX,maxn;
int main(){
	//freopn("and.in","r",stdin);
	//freopn("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			minn=min(a[i],a[j]);
		}
		maxn=max(maxn,minn);
	}
	cout<<maxn;
}
