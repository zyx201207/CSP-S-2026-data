#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000001;
long long m,n,a[MAXN],ans=0,sum=1,cnt=0,maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1) cout<<a[1];
	if(n==2){
		if(m==1){
			ans=max(a[1],a[2]);
			cout<<ans;
			return 0;
		}
		ans=a[1]&a[2];
		cout<<ans;
		return 0;
	}
	if(n==m){
	for(int i=1;i<n;i++){
		ans=a[i]&a[i+1];
		a[i+1]=a[i]&a[i+1];
	}
	cout<<ans;
	return 0;
}
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		ans=a[i]&a[j];
    		a[i]=a[i]&a[j];
    		sum++;
    		if(sum==m) break;
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
