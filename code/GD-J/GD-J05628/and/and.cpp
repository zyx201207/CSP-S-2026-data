#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005];
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[1]=a[n];
	b[n]=1;
	if(m==1){
		cout<<f[1];
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&(a[i]&a[j])>ans){
					ans=(a[i]&a[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++)
		a[i]&=a[i-1];
		cout<<a[n];
		return 0;
	}
	for(int i=2;i<=m;i++){
		int maxx=0,cnt=0;
		for(int j=1;j<=n;j++){
			if((f[i-1]&a[j])>maxx&&b[j]!=1){
				maxx=(f[i-1]&a[j]);
				cnt=j;
			}
		}
		f[i]=maxx;
		b[cnt]=1;
	}
	cout<<f[m];
	return 0;
}
