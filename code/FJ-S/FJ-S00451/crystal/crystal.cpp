#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=1e4+10;
int n,m,res,a[N],b[N],c[M][M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=9001){
		for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				c[i][j]=c[i][j-1]+b[j]*(j-i);
				if(c[i][j]<=m){
					if(j-i+1>res){
						res=j-i+1;
					}
				}
			}
		}
		cout<<res;
		return 0;
	}
	int p=abs(a[2]-a[1]);
	for(int i=n;i>=1;i--){
		int q=i*(i-1)/2;
		if(q*p<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
