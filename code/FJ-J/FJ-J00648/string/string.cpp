#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n;
struct s{
	ll k;
	char c;
}a[N];



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	ll l=1,r=n;
	ll ans=0;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].k>a[r].k){
				r--;
				a[l].k-=a[r+1].k;
			}else if(a[r].k>a[l].k){
				l++;
				a[r].k-=a[l-1].k;
			}else{
				r--;
				l++;
			}
		}else{
			if(a[l].k>a[r].k){
				r--;
				a[l].k-=a[r+1].k;
				ans+=a[r+1].k;
			}else if(a[r].k>a[l].k){
				l++;
				a[r].k-=a[l-1].k;
				ans+=a[l-1].k;
			
			}else{
				r--;
				l++;
				ans+=a[l-1].k;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}