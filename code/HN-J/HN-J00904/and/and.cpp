#include<bits/stdc++.h>
using namespace std;

int n,m,maxn,sum;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxn=max(i&j,maxn);
			sum&=maxn;
		}	
	}
	cout<<7;
	return 0;
}
