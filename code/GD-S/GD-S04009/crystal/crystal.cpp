#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],ans=0,len2=0;
vector<int> b;
vector<int> cha;
int len;
int zws=0;
bool check(int x){
	int cnt=0,num=0;
	for(auto &p:cha){
		if(num>=x) break;
		num++;
		cnt+=p;
	}
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0){b.push_back(a[i]);len++;}
		else len2++;
	}
	sort(a+1,a+1+n);
	sort(b.begin(),b.end());
	for(int i=len/2;i<len;i++){
		zws=b[i];
		for(int i=1;i<=n;i++){
			if(i==(i+1)/2+len2) continue;
			if(zws>=a[i]) cha.push_back(abs(zws-a[i]));
		}
		sort(cha.begin(),cha.end());
		int len23=cha.size();
		int l=0,r=len23;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(check(mid)){
				l=mid+1;
				ans=max(ans,mid);
			}else{
				r=mid-1;
			}
		}
		cha.clear();
	}
	cout<<ans;
	return 0;
}
