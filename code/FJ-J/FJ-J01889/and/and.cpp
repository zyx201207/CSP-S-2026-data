#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,ans,l,an,yy;
ll a[200005],t[35];
bool b[200005],y;
string s[200005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(ll i=1;i<=35;i++){
		ans=ans*2+1;
	}
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		s[i]="0000000000000000000000000000000000";
	}
	for(ll i=1;i<=n;i++)b[i]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ll x=1,ss=a[i];
		while(ss>0){
			if(ss%2==1){
				t[x]++;
				s[i][x]='1';
			}
			else s[i][x]='0';
			x++;
			ss/=2;
			
		}
		l=max(l,x-1);
	}
	y=0;
	for(ll i=l;i>=1;i--){
		if(t[i]>=m){
			if(y==0){
				for(ll j=1;j<=n;j++){
					if(s[j][i]=='1'){
						b[j]=1;
						an++;
						
					}
				}
				y=1;
			}
			else{
				for(ll j=1;j<=n;j++){
					if(an==m)break;
					if(s[j][i]=='0'&&b[j]==1){
						b[j]=0;
						an--;
					}
				}
			}
			
		}
		if(t[i]==m)break;
		if(an==m)break;
	}
	for(ll i=1;i<=n;i++){
		if(b[i]==1){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}


