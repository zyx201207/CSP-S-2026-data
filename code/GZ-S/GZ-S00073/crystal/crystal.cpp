//毕节七星关东辰实验学校 刘杰 GZ-S00073
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MX=6e5+10;
int a[MX],s[MX];int n,m;
unordered_map<int,int> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		mp[a[i]]++;
	}
	int l=1,r=1000000000000000000;
	int ans=0;
	while(l<r){
		int mid=l+(r-l)/2;
		int k=lower_bound(a+1,a+n+1,mid)-a;
		int h;
		if(k>n){
			h=n;
		}
		else h=k-1;
		if((h*mid-s[h])<=m&&(h*mid-s[h])>=0){
			//cout<<mid<<" "<<h<<" "<<h*mid-s[h]<<endl;
			ans=max(ans,h+mp[mid]);
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans<<endl;
}
