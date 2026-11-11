#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using ll=long long;
struct T{
	int x;
	char c;
};
T a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i]={x,c};
	}
	ll len=0;
	ll ans=0;
	for(int l=1,r=n;l<=r;l++){
		ll el=len;
		len+=a[l].x;
		char c=a[l].c;
		while(el+a[r].x<=len){
			el+=a[r].x;
			if(c!=a[r].c){
				ans+=a[r].x;
			}
			r--;
		}
		if(el<len){
			if(c!=a[r].c){
				ans+=(len-el);
			
			} 
			a[r].x-=(len-el); 
		}
	}
	cout<<ans;
	return 0;
} 
