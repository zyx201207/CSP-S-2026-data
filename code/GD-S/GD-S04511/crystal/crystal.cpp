#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long m,a[N],ans=1;
int n;
map<long long,int>mp;
void chk(int d){
	long long s=0,cnt=mp[a[d]];
	for(int i=d-1;i>=1;i--){
		if((a[d]-a[i])*mp[a[i]]+s>m){
			cnt+=(m-s)/(a[d]-a[i]);
			break;
		}
		s+=(a[d]-a[i])*mp[a[i]];
		cnt+=mp[a[i]];
	}
	ans=max(ans,cnt);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];mp[a[i]]++;
		if(mp[a[i]]>1)i--,n--;
	}
	stable_sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)chk(i);//,cout<<a[i]<<":"<<ans<<"\n";
	cout<<ans;
	return 0;
}
