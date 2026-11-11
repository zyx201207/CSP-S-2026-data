#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,m=0,cnt=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	m+=a[i];
	}
	m/=2;
	ll m1=m,m2=m;
	string x="",y="";
	ll q=1,p=n;
	while(m1>0){
		if(a[q]<=m1){
			m1-=a[q];
			for(ll i=1;i<=a[q];i++){
				x+=c[q];
			}
			q++;
		}else{
			for(ll i=1;i<=m1;i++){
				x+=c[q];
			}
			m1=0;
		}
	}
	while(m2>0){
		if(a[p]<=m2){
			m2-=a[p];
			for(ll i=1;i<=a[p];i++){
				y+=c[p];
			}
			p--;
		}else{
			for(ll i=1;i<=m2;i++){
				y+=c[p];
			}
			m2=0;
		}
	}
	for(ll i=0;i<m;i++){
		if(x[i]!=y[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

