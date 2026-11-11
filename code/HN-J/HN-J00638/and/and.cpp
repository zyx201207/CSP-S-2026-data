#include<bits/stdc++.h>
using namespace std;
const int N=1E5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]!=a[j])now=a[i]&a[j];
		}
		maxn=max(maxn,now);
	}
	cout<<maxn;
	return 0;
} 
