#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,l;
long long m,a[N],k,len,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=1;len=1;
	for(int r=2;r<=n;r++){
		k+=(a[r]-a[r-1])*len;
		ans=max(ans,len);
		while(k>m){
			k-=(a[r]-a[l]);
			l++;len--;				
		}
		len++;
	}
	cout<<ans;
	return 0;
}
