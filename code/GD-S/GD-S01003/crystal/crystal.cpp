#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	int ans=0;
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int k=j-(j-i)/2;
			int lc=a[k]*(k-i+1)-(d[k]-d[i-1]);
			int rc=(d[j]-d[k-1])-a[k]*(j-k+1);
			if(lc+rc<=m){
				ans=len;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
