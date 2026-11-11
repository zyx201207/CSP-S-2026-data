#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int a[N];
int s[N];
int n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	//s[i]-s[j-1]+m>=a[i]*(i-j+1)
	//-s[j-1]>=a[i]*(i-j+1)-m-s[i]
	//s[j-1]<=-a[i]*(i-j+1)+m+s[i]
	int ans=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid;
//		int temp=i;
//		cout<<i<<" : \n";
		while(l<r){
			mid=l+r>>1;
//			cout<<l<<" -> "<<r<<"\n";
//			cout<<s[i]-s[mid-1]<<" + "<<m<<" "<<a[i]*(i-mid+1)<<"\n";
			if(s[i]-s[mid-1]+m>=a[i]*(i-mid+1)){
				r=mid;
//				temp=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-r+1);
//		cout<<r<<" ~ "<<i<<"\n";
	}
	cout<<ans;
	return 0;
}

