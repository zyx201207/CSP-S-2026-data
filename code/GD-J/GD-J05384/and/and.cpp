#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
const ll N=2e5+10;
ll a[N][33];
ll b_c[N];
ll n,m,ans;
ll qp(ll x){
	if(x==0)return 1;
	ll sum=qp(x/2);
	sum*=sum;
	if(x%2==1){
		sum*=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll t;
		cin>>t;
		for(ll j=32;j>=0;j--){
			ll z=qp(j);
			if(t>=z){
				//cout<<1;
				a[i][j]++;
				t-=z;
			}
		}
	}
	//cout<<1;
	ll ini=0;
	ll sum=0;
	for(ll i=32;i>=0;i--){
		ll chice[N]={0},sum1=0;
		for(ll j=1;j<=n;j++){
			if(a[j][i]){
				//cout<<sum1;
				sum1++;
				chice[sum1]=j;
			}
		}
		//cout<<sum1;
		if(sum1>=m){
			ans+=qp(i);
			for(ll i=1;i<=sum1;i++){
				b_c[i]=chice[i];
				//cout<<b_c[i];
			}
			ini=i-1;
			sum=sum1;
			break;
		}
	}
	for(ll i=ini;i>=0;i--){
		ll summ=0;
		ll chice[N]={0};
		for(ll j=1;j<=sum;j++){
			if(b_c[j]==0)continue;
			//cout<<b_c[j]<<";";
			if(a[b_c[j]][i]==1){
				summ++;
				chice[summ]=b_c[j];
//				if(i==1){
//					cout<<j<<";";
//				}
			}
		}
		if(summ>=m){
			ans+=qp(i);
			ll j=1,k=1;
			for(ll k=1;k<=sum;k++){
				while((b_c[j]==0||b_c[j]<chice[k])&&(j<=k)){
					//cout<<k<<";";
					b_c[j]=0;
					j++;
				}
				if(b_c[j]==chice[k]){
					j++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
