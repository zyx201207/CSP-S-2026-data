#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,a[200005],tool[40],ans=0;
bool flag[200005];
string s[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	tool[1]=1;
	for(ll i=2;i<=35;i++){
		tool[i]=tool[i-1]*2;
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=35;j>=1;j--){
			if(a[i]>=tool[j]){
				s[i]+='1';
				a[i]-=tool[j];
			}else{
				s[i]+='0';
			}
		}
	} 
	for(ll i=1;i<=35;i++){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(flag[j]){
				continue;
			}
			if(s[j][i]=='1'){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=tool[35-i];
			for(ll j=1;j<=n;j++){
				if(s[j][i]=='0'){
					flag[j]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
