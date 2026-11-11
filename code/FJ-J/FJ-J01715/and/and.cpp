#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,m,mmax=0;
ll cnt[N][35],ans[35],a[N];
bool flag=false;
void to_2(ll x,ll i){
	ll j=0;
	ll y=x;
	while(y>0){
		if(y%2==0){
			cnt[i][j]=0;
			flag=true;
		}else cnt[i][j]=1;
		j++;
		y/=2;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("eee.in","r",stdin);//调试用
//	freopen("and.out","w",stdout);//调试用
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
//	cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mmax=max(mmax,a[i]);
		to_2(a[i],i);
	}
	if(m==1){
		cout<<mmax;
	}else if(m==2){
		ll an=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ll sun=0;
				for(int k=0;k<=30;k++){
					if(cnt[i][k]==1&&cnt[j][k]==1){
						sun+=pow(2,k);
					}
				}
				an=max(an,sun);
			}
		}
		cout<<an;
	}else if(m==n){
		for(int j=0;j<=30;j++){
			bool can=true;
			for(int i=1;i<=n;i++){
				if(cnt[i][j]==0)can=0;
			}
			if(can){
				ans[j]=1;
			}
		}
		ll sum=0;
		for(int i=0;i<=30;i++){
			if(ans[i]==1){
				ll j=i;
				ll no=1;
				while(j--){
					no*=2;
				} 
				sum+=no;
			}
		}
		cout<<sum;
	}else if(!flag){
		sort(a+1,a+1+n);
		cout<<a[n+1-m];
	}
	
	return 0;
}

