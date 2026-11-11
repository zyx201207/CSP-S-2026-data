#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+5;
struct node{
	ll s,e;
};
int n;
ll a[N];
char c[N]; 
node area[N];
ll l,r,len;
ll i,j;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		area[i].s=area[i-1].e+1;
		area[i].e=area[i].s+a[i]-1;
		len+=a[i];
	}
	l=1;r=len;i=1;j=n;
	while(l<r){
		if(a[i]<a[j]){
			l=area[i].e+1;
			r=area[j].e-a[i];
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			i++;
			area[j].e=r;
			a[j]=area[j].e-area[j].s+1;
		}else{
			if(a[i]>a[j]){
				l=area[i].s+a[j];
				r=area[j].s-1;
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				j--;
				area[i].s=l;
				a[i]=area[i].e-area[i].s+1;
			}else{
				l=area[i].e+1;
				r=area[j].s-1;
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}

