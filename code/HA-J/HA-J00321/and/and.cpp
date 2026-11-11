#include<bits/stdc++.h>
using namespace std;

int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxr=-1;
	for(int i=1;i<=n;i++){
		int res=a[i];
		for(int j=i+1;j<=i+m;j++){
			res&=a[j];
		}
		maxr=max(maxr,res);
	}
	cout<<maxr;
}

