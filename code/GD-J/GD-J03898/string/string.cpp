#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll n,a[maxn],mid,l,r,i,j,ans;
char c[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	mid/=2;
	j=n;
	i=0;
	while(r!=mid){
		if(l==r){
			i++;
			if(l+a[i]<=mid)l+=a[i];
			else l=mid;
		}
		else if(l>r)j--;
		if(c[i]==c[j]){
			r+=min(a[i],a[j]);
			if(r>mid)r=mid;
		}
		else{
			if(r+min(a[i],a[j])>mid){
				ans+=mid-r;
				r=mid;
			}
			else{
				ans+=min(a[i],a[j]);
				r+=min(a[i],a[j]);
			}
		}
	}
	cout<<ans;
	return 0;	
}
//Trick||Treat!
