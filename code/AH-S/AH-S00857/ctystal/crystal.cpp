#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],c[500050],ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	int j=n-1;
	for(int i=n-2;i>=0;i--){
		cnt+=c[j]-c[i];
		if(cnt<=m) ans=max(ans,(long long)(j-i+1));
		else{
			while(cnt>m){
				cnt-=(c[j]-c[j-1])*(j-i);
				j--;
			}
			ans=max(ans,(long long)(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
