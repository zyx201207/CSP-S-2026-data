#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1145141];
int sum[1145141];
signed main(){//freopen("crystal1.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		sum[i]+=a[i];
	}int l=1;
	int maxx=0;
	for(int r=1;r<=n;r++){
		while((a[r]*(r-l+1))-(sum[r]-sum[l-1])>m){
			l++;
		}maxx=max(maxx,r-l+1);
	}cout<<maxx<<endl;
}
