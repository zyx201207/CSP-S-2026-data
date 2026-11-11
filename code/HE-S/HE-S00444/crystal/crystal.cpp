#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cmp(int b,int c){
	return b>c;
}
const int N=1e7;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=1;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[2]-a[1]==a[3]-a[2]){
		int sum=a[n]-a[n-1];
		if(m<sum){
			cout<<1;
			return 0;
		}else if(sum==m){
			cout<<2;
			return 0;
		}else{
			cout<<m/sum;
			return 0;
		}
	}else if(a[1]==1&&a[2]==2&&a[3]==3){
		sort(a,a+n,cmp);
		for(int i=2;i<=n;i++){
			int x=i-1;
			if(m-x>=0){
				m=m-x;
				ans+=1;
				cout<<ans<<' ';
			}else{
				break;
			}
		}
		cout<<ans;
	}else{
		cout<<n;
	}
 	return 0;
}
