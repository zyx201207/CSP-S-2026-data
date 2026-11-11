#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10;
int n,m;
int a[N];
int d[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		int f=0;
		int cnt=N;
		while(f<=20){
			int mid=l+r>>1;
			int value=(i-mid)*a[i]-(d[i-1]-d[mid-1]);
			if(value>m)l=mid+1;
			else{
				r=mid-1;
				cnt=min(cnt,mid);
			}
			f++;
		}
		ans=max(ans,i-cnt+1);
	} 
	cout<<ans;
    return 0;
}

