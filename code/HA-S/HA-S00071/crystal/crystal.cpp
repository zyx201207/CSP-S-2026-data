#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
vector<long long>a,pre;
struct Num{
	long long pos,cnt,val;
};
vector<Num>nums;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	long long val=a[1];
	for(int i=1,cnt=1;i<=n;i++)if(a[i+1]==val)cnt++;
	else nums.push_back((Num){i-cnt,cnt,val}),cnt=1,val=a[i+1];
	pre.resize(n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(Num num:nums){
		int l=0,r=num.pos;
		while(l<=r){
			int mid=(l+r)/2;
			if(num.val*(num.pos-mid)-pre[num.pos]+pre[mid]<=m)ans=max(ans,num.cnt+num.pos-mid),r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
