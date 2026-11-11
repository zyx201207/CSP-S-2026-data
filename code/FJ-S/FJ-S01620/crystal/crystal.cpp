#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500050],n,m,ans=1;
int b[500050],c[500050];
bool check(int num,int x){
	int cha=num-x;
//	cout<<num<<' '<<x<<' '<<a[num]*cha-b[num-1]+b[x]<<' '<<m<<endl;
	return a[num]*cha-b[num-1]+b[x-1]<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int xx=0;
	
	for(int i=1;i<=n;i++){
		xx+=a[i];
		b[i]=xx;
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
//			cout<<l<<' '<<r<<' '<<mid<<' '<<endl;
			if(check(i,mid)) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
//		cout<<ans<<endl;
	}
	cout<<ans;
}
