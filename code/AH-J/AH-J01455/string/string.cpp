#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,cnt,a[200005],b[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n%2==1)ans=n/2+2;
	else ans=n/2+1;
	for(int i=1;i<=n/2;i++){
		for(int j=n-i+1;j>=ans;j--){
			if(c[i]!=c[j]){
				if(i==n/2&&n%2==0){
					cnt+=min(b[i],b[j]);
					cnt+=abs(b[i]-b[j]);
					break;
				}
				cnt+=min(b[i],b[j]);
				if(b[j]<b[i])b[i+1]+=b[i]-b[j];
				else b[j-1]+=b[j]-b[i];
			}
			break;
		}
	}
	if(n%2==1){
		cnt+=b[n/2+1];
		if(c[n/2+1]!=c[n/2]&&c[n/2+1]!=c[n/2+2])cnt-=a[n/2+1];
	}
	cout<<cnt;
	return 0;
}
