#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
int l,r,res;
map <long long,int> mp;
int check(int x){
	long long last=m;
	int ans=0;
	//cout<<a[x]<<":"<<mp[a[x]]<<"\n"; 
	for(int i=x-1;i>=1;i--){
		long long cnt=last/(a[x]-a[i]); 
		if(cnt>=(long long)mp[a[i]]||last-mp[a[i]]*(a[x]-a[i])>0) last-=mp[a[i]]*(a[x]-a[i]),ans+=mp[a[i]];
		else return ans+cnt+mp[a[x]];
	}
	return ans+mp[a[x]];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) mp[a[i]]++;
	l=1,r=unique(a+1,a+n+1)-(a+1);
	while(l<=r){
		int mid=(l+r)/2;
		int flag=check(mid);
		if(flag){
			l=mid+1;
			res=max(res,flag);
			//cout<<mid<<":"<<res<<"\n"; 
		}else{
			r=mid-1;
		}
	}
	cout<<res;
	return 0;
}
