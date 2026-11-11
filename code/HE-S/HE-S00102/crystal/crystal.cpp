#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	int l=1,r=2,m1=m,ans=1,cnt=1;
	for(int i=2;i<=n;i++){
			while(m1<(a[i]-a[i-1])*(r-l)&&l<r){
				m1+=a[i-1]-a[l];
				l++;
				cnt--; 
			}m1-=(a[i]-a[i-1])*(r-l);
			cnt++;
			r++;
		ans=max(cnt,ans);
		if(cnt+n-i<ans){
				break;
		}
	}cout<<ans;
	return 0;
}//Oct31==Dec25?
