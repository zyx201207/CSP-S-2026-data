#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,m,a[N],ch[N][N],sum,cnt,ans;
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	if(m>1e9){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ch[j][i]=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		sum=0,cnt=0;
		for(int j=i;j>=1;j--){
			cnt++;
			if(sum+ch[j][i]>=m){
				ans=max(ans,cnt);
//				cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<ans<<'\n';
				break;
			}
			sum+=ch[j][i];
		}
	}
	cout<<ans;
	return 0;
}
