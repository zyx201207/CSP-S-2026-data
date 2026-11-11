#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out() (cout<<"sb\n")

const int N=5e5+5;

int n,m,a[N],b[N],s[N];

signed main(){
//	system("fc crystal.in crystal.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++) s[i]=s[i-1]+(i-1)*b[i];
	int ans=0;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(s[i]-s[mid]-(a[i]-a[mid])*(mid-1)<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}

