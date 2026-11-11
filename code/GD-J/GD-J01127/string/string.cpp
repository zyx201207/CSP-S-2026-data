#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
char c[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int ans=0;
	for(int i=1,j=n;i<j;i++){
		while(a[i]>0){
			if(c[j]==c[i]){
				if(a[i]>=a[j]) a[i]-=a[j],a[j]=0;
				if(a[i]<a[j]) a[j]-=a[i],a[i]=0;
			}
			else{
				if(a[i]>=a[j]) ans+=a[j],a[i]-=a[j],a[j]=0;
				if(a[i]<a[j]) ans+=a[i],a[j]-=a[i],a[i]=0;
			}
			if(a[j]<=0) j--;
		}
	}
	cout<<ans;
	return 0; 
}
