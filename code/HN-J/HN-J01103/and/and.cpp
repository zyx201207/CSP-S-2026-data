#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200003],b[200003],t,d[200003][35],num;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			d[i][j]=(a[i]>>j)&1;
		}
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=d[b[j]][i];
		}
		if(sum>=m){
			num+=(1<<i);
			t=0;
			for(int j=1;j<=n;j++){
				if(d[b[j]][i]){
					b[++t]=b[j];	
				}
			}
			n=t;
		}
	}
	cout<<num;
	return 0;
}

