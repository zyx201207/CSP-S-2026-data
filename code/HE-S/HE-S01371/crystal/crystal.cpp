#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;
struct cr{
	int val;
	bool flag;
}a[N];
bool cmp(cr a,cr b){
	return a.val<b.val;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	sort(a+1,a+1+n,cmp);
	int ans=1;
	for(int i=1;i<=n;i++){
		if(a[i+1].val-a[i].val>m) a[i].flag=false;
		else a[i].flag=true;
	}
	for(int i=1;i<=n;i++){
		int j=i-1,cnt=1,now=m;
		while(now>0&&j>=1){
			if(a[j].flag&&now>0){
				now-=(a[i].val-a[j].val);
				cnt++;
				ans=max(ans,cnt);
			}else{
				ans=max(ans,cnt);
				break; 
			}
			j--;
		}
	}
	cout<<ans;
	return 0;
} 
