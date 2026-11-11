#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m,ans,mid,res,cnt;
ll a[N],diff[N];
bool check(int mid){
	cnt=0;
	for(int i=1;i<=mid;i++){
		cnt+=(a[mid]-a[i]);
	}
	if(cnt>m)return 0;
	else return 1; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;		
		}else{
			r=mid-1;
		}
	}cout<<mid-1;
	return 0;
}
