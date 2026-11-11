#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,a[N],cnt;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n,x=a[1],y=a[n];
	while(l<r){
		if(c[l]==c[r]){
			if(x>y){
				x-=y;
				r--;
				y=a[r];
			}
			else if(x<y){
				y-=x;
				l++;
				x=a[l];
			}
			else{
				l++;
			    r--;
			    x=a[l];
			    y=a[r];
			}
		}
		else{
			if(x>y){
				cnt+=y;
				x-=y;
				r--;
				y=a[r];
			}
			else if(x<y){
				cnt+=x;
				y-=x;
				l++;
				x=a[l];
			}
			else{
				cnt+=x;
				l++;
				r--;
				x=a[l];
				y=a[r];
			}
		}
	}
	cout<<cnt;
	return 0;
}
