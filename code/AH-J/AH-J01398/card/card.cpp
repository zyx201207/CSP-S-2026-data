#include<bits/stdc++.h>
using namespace std;
int a[200005],r[200005],cnt=1;
int f[200005],z[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=n;
	for (int i=1;i<=k;i++){
		if (a[i]==a[i-1]) n--;
	}
	long long ans=0;
	for (int i=1;i<=n;i++){
		ans+=n-i+1;
	}
	cout<<ans<<endl;
	return 0;
}

