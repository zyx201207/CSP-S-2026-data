#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans=1;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<n;i++){
		long long x=m,cnt=0,l=i-1;
		do{
			x=x-(a[i]-a[l]);
			cnt++;
			l--;
		}while(x>0 && l>0);
		ans=max(ans,cnt);
	}
	cout<<ans+1;
} 
