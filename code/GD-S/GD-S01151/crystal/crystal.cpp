#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int cnt=1,ans=1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,used=0;
	int maxn=0;//当前与已选最小水晶之差 
	for(int i=2;i<=n;i++){
		int cha=a[i]-a[i-1];
		cnt++;
		maxn+=cha;
		used+=(cnt-1)*cha;
		while(used>m){
			cnt--;
			used-=maxn;
			maxn-=a[l+1]-a[l];
			l++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
}
//15:03 测大样例通过 
