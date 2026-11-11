#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],aa[200005],n,s,ans;
char c[200005],cc[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		aa[i]=a[i],cc[i]=c[i];
		s+=a[i];
	}
	int mid=(n%2==0?n/2:(n+1)/2);
	for(int i=1,j=n;i<=mid;){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>=a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}else{
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}

