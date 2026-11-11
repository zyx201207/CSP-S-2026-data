#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
struct no{
	ll val; int ci;
};
const int maxn=5000005;
ll n,m,tot=0;
ll a[maxn],ans;
no aa[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; aa[i].val=-1;
	}
	sort(a+1,a+1+n);
	a[0]=-1;
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1]){
			aa[tot].ci++;
		}
		else{
			aa[++tot].val=a[i+1]; aa[tot].ci=1;
		}
	}
	ll ans=aa[1].ci;
	for(int i=2;i<=tot;i++){
		ll tmp=aa[i].ci,mm=m;
		for(int j=i-1;j>=1;j--){
			for(int k=1;k<=aa[j].ci;k++){
				if(mm-(aa[i].val-aa[j].val)>=0){
					mm-=(aa[i].val-aa[j].val);
					tmp++;
				}
				else break;
			}
			if(mm<=0) break;
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<"\n";
	
	return 0;
}//15:20 ÇÐµôT1 
