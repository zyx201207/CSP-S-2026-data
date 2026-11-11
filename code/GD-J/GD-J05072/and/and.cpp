#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
map<int,int>mp;
int a[N];
int n,m,ans,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x==0)continue;
		if(mp[x]==0)a[++cnt]=x;
		mp[x]++;
		if(mp[x]>=m)ans=max(ans,x);
	}
	stable_sort(a+1,a+1+n,cmp);
	for(int i=1;i<=cnt&&a[i]>ans;i++){
		int s=mp[a[i]];
		for(int j=1;j<i;j++){
			if((a[j]&a[i])==a[i])s+=mp[a[j]];
			if(s>=m)return cout<<a[i],0;
		}
	}
	cout<<ans;
	return 0;
}
