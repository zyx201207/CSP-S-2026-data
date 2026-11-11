#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500010;
int n;
ll m,a[N];
__int128 s1[N],s2[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)s1[i]=s1[i-1]+a[i]-a[i-1];
	for(int i=2;i<=n;i++)s2[i]=s2[i-1]+(a[i]-a[i-1])*(i-1);
	int mx=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n,res=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((s2[mid]-s2[i])-(i-1)*(s1[mid]-s1[i])>m)res=mid,r=mid-1;
			else l=mid+1;
		}
		mx=max(mx,res-i);
	}
	cout<<mx;
    return 0;
}
