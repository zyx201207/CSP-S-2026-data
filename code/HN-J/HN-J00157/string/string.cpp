#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N=2e5+5;
ll n;
struct P{
	ll a;
	char c;
};
P z[N],f[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>z[i].a>>z[i].c,f[i]=z[i];
	ll sum=0;
	ll j=n;
	for(ll i=1;i<=n;i++){
		while(z[i].a!=0){
			if(z[i].a>=f[j].a){
				if(z[i].c!=f[j].c)sum+=f[j].a;
				z[i].a-=f[j].a;
				j--;
			}
			else{
				if(z[i].c!=f[j].c)sum+=z[i].a;
				f[j].a-=z[i].a;
				z[i].a=0;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
