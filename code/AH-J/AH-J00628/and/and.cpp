#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[410000];
string b[410000];
void sel50(){
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll maxn=0;
	for(int i=1;i<=n-m+1;i++){
		ll cnt=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			cnt&=a[j];
		}
		maxn=max(cnt,maxn);
	}
	cout<<maxn;
	return ;
}
void sel70(){
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	if(a[1]%2==1)cout<<a[m];
	else cout<<a[1];
}
void sel100(){
	ll ms=0;
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll j=a[i];
		while(j){
			b[i]+=j%2+'0';
			j/=2;
		}
		ms=max(ms,ll(b[i].size()));
	}
	for(int i=1;i<=n;i++){
		if(ll(b[i].size())<ms){
			for(int j=1;j<=ms-ll(b[i].size());j++){
				b[i]+='0';
			}
		}
		reverse(b[i].begin(),b[i].end());
	}
	ll c2=1,c3=n,ans=0;
	for(int i=0;i<ms;i++){
		ll cnt=0;
		for(int j=c2;j<=c3;j++){
			if(b[j][i]=='1'){
				cnt++;
			}else {
				c2+=cnt;
				if(cnt<2){
					ans*=2;
					break;
				}
				ans=ans*2+1;
				c3=j-1;
				break;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2000){
		sel50();
	}else{
		sel70();
	}
	return 0;
}
