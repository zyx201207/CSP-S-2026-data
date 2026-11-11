#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &n){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
void read(ll &n){ll x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
const int N=5e5+5;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	ll l=1,ans=1;
	ll summ=0;
	for(ll r=1;r<=n;r++){
//		cout<<r<<endl;
		summ+=(r-l)*(a[r]-a[r-1]);
		while(l<r&&summ>m){
			summ-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

