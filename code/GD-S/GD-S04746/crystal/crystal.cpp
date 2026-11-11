#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long b[5005][5005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=a[j]-a[i];
		}
	}
	long long maxn=-1;
	for(int i=1;i<=n;i++){
		long long cnt=0,ans=0;
		long long o[5005]={0};
		for(int j=1;j<=i;j++){
			o[j]=b[j][i];
		}
		for(int j=1;j<=i;j++){
			cnt+=o[j];
			if(cnt>m){
				break;
			}else{
				ans=ans+1;
			} 
		} 
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
} 
