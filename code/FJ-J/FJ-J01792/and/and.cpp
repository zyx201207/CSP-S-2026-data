#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=-1e8,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(n-i>=1) sum=a[i] and a[i+1];
		else sum=a[n] and a[1];
		if(sum>=ans) ans=sum;
		sum=0;
	}
	cout<<ans;
}
