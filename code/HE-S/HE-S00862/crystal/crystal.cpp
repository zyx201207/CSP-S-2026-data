#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],pre[N],cha[N],cnt=1,ans,sum;
bool ok;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		if(i>2&&cha[i]!=cha[i-1]){
			ok=1;
		}
	}
	if(ok==0){
		for(int i=2;i<=n;i++){
			pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
			if(pre[i]>m){
				break;
			}
			cnt++;
		}
		cout<<cnt<<'\n';
		return 0;
	}
	for(int l=1;l<=n;l++){
		cnt=1;
		sum=0;
		for(int r=l;r<=n;r++){
			sum+=(a[r]-a[r-1])*(r-l);
			if(sum>m){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt-1);
	}
	cout<<ans;
	return 0;
}
