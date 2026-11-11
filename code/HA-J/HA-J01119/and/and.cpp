#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,a[200010],b[200010][40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	mx=a[n-m+1];
	for(int i=1;i<=n;i++){
		int s=a[i];
		for(int j=30;j>=0;j--){
			if(s>=(1<<j)){
				s-=(1<<j);
				b[i][j]=1;
			}
		}
	}
	for(int i=mx;i>=0;i--){
		int s=i,sum=0,f[40]={0};
		for(int j=30;j>=0;j--){
			if(s>=(1<<j)){
				s-=(1<<j);
				f[j]=1;
			}
		}
		int g=lower_bound(a+1,a+n+1,i)-a;
		for(int k=g;k<=n;k++){
			int t=1;
			for(int j=30;j>=0;j--){
				if(f[j]==1&&b[k][j]==0){
					t=0;
				}
			}
			sum+=t;
		}
		if(sum>=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}

