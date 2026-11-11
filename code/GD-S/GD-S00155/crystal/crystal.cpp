#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c;
bool f=true;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	c=a[2]-a[1];
	for (int i=3;i<=n;i++){
		if (a[i]-a[i-1]!=c){
			f=false;
			break;
		}
	}
	if (f){
		for (int i=1;i<=n;i++){
			ans+=c*i;
			if (ans>m){
				cout<<i;
				return 0;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			b[i]+=a[i]-a[j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			
			if (b[i]<=m){
				
				//cout<<i<<" "<<j<<"\n";
				ans=max(ans,i-j+1);
			}
			b[i]-=a[i]-a[j];			
		}
	}
	cout<<ans;
	return 0;
	/**/
}
