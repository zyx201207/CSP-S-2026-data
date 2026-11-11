#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans;
struct Node{
	ll g;
	char c;
}a[300010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i].g>>a[i].c;
	ll l=1,r=n;
	while(l<r){
		if(a[l].g==0) l++;
		if(a[r].g==0) r--;
		if(a[l].g==a[r].g&&a[l].c==a[r].c) l++,r--;
		else if(a[l].c==a[r].c&&a[l].g>a[r].g) a[l].g-=a[r].g,r--;
		else if(a[l].c==a[r].c&&a[l].g<a[r].g) a[r].g-=a[l].g,l++;
		else if(a[l].c!=a[r].c){
			if(a[l].g>=a[r].g) ans+=a[r].g,a[l].g-=a[r].g,r--;
			else ans+=a[l].g,a[r].g-=a[l].g,l++;
		}if(a[l].g==0) l++;
		if(a[r].g==0) r--;
	}cout<<ans;
	return 0;
}

