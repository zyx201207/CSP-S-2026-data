#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,res;
ll m;
ll a[N];
bool check(int i,int x){
	//cout<<a[i]*(i-x+1)-a[i-1]<<endl;
	if(a[i]*(i-x)-(a[i-1]-a[x-1])<=m) return 1;
	else return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans;
		while(l<=r){
			//cout<<l<<" "<<r<<endl;
			int mid=(l+r)>>1;
			if(check(i,mid)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
			
		}
		a[i]+=a[i-1];
		//cout<<"#"<<ans<<" "<<i-ans+1<<endl;
		res=max(i-ans+1,res);
	}
	printf("%d\n",res);
	return 0;
} 
