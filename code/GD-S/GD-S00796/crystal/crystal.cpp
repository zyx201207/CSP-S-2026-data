#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5; 
int n,a[N],m,sum[N],ss[N];
bool check(int x){
	int ll=1,s=0;
	for(register int i=1;i<=n;i++){
		s=s+sum[i]*(i-ll);
//		cout<<i<< " "<<s<<'\n';
		if(s<=m){
			if(i-ll+1==x){
				return 1;
			}
		}
		else{
			while(ll<=i){
				s-=(ss[i]-ss[ll]);
				ll++;
				if(s<=m){
					break;
				}
			}
		}
//		cout<<x<<" "<<i<<" "<<sum[i]<<" "<<s<<'\n';
	//	cout<<sum[i]<<" "<<s<<'\n';
	}
	return 0;
} 
int ef(){
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(register int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
	}
	for(register int i=1;i<=n;i++){
		ss[i]=ss[i-1]+sum[i];
	}
	cout<<ef()<<'\n';
	return 0;
}
//5 4
//1 1 2 2 3

