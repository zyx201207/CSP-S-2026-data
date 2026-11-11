#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
typedef long long ll;
string s; 
ll ans,n,a[N],sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}   
		}
		if(sum%2){
		    ll mid=sum/2;
		    for(int i=1;i<=mid;i++){
		    	if(s[mid+i]!=s[mid-i]) ans++;
			}
		}
		else{
			ll mid=sum/2;
			for(int i=1;i<=mid;i++){
		    	if(s[mid+i-1]!=s[mid-i]) ans++;
			}
		}
	}
	else{
		ll l=1,r=n;
		while(l<r){
			if(a[l]>a[r]){
				while(a[l]>0){
					if(a[l]-a[r]<0){
						if(c[l]!=c[r]) ans+=a[l];
						a[r]-=a[l];
						break;
					}
					if(c[l]!=c[r]) ans+=a[r];
					a[l]-=a[r];
					r--;
				}
				l++;
			}
			else if(a[l]<a[r]){
				while(a[r]>0){
					if(a[r]-a[l]<0){
						if(c[l]!=c[r]) ans+=a[r];
						a[l]-=a[r];
						break;
					}
					if(c[l]!=c[r]) ans+=a[l];
					a[r]-=a[l];
					l++;
				}
				r--;
			}
			else{
				if(c[l]!=c[r]) ans+=a[l];
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}