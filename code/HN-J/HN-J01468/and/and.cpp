#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cnt[35],m,n,a[245000],k,l,sum,ans;
vector<ll> s[35];
bool b[35][245000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) continue;
		ll len=0,p=1,num=a[i];
		while(a[i]>p){
			len++;
			p*=2;
		}
		while(num>0){
			if(num>=p){
				num-=p;
				cnt[len]++;
				s[len].push_back(i);
			}
			len--;
			p/=2;
		}
	}
	sum=pow(2,31);
	for(int i=1;i<=n;i++) b[0][i]=true;
	for(int i=30;i>=0;i--){
		sum/=2;
		if(cnt[i]>=m){
			++l;
			ll k=0;
			for(int v:s[i]){
				b[l][v]=b[l-1][v];
				if(b[l][v]) k++;
			}
			if(k>=m) ans+=sum;
			else l--;
		}
	}
	cout<<ans;
	return 0;
}


