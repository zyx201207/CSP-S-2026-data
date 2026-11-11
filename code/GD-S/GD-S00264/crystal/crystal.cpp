#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,k,mx,a[N],s[N];
bool check(int x,int y,int k){
	int num=0;
	num+=(k-x+1)*y;
	num-=s[k]-s[x-1];
	return num<=m;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid,sum=1;
		while(l<r){
			mid=l+r>>1;
			if(check(mid,a[i],i)) r=mid;
			else l=mid+1;
		}
		sum+=i-l;
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
//Oct31==Dec25?

