#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c[200005];
ll n,a[200005],ans,l,num,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	num=a[l]-a[r];
	while(l<r){
		if(num>0){
			if(c[l]!=c[r]){
				ans+=a[r];
				a[l]-=a[r];
			}
			r--;
			num-=a[r];
		}
		else if(num<0){
			if(c[l]!=c[r]){
				ans+=a[l];
				a[r]-=a[l];
			}
			l++;
			num+=a[l];
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;
			num=a[l]-a[r];
		}
	}
	cout<<ans;
}
