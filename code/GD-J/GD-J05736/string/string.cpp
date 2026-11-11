#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+2;
int a[N];char s[N];int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(s[l]!=s[r]){
				ans+=a[l];
				a[r]-=a[l];
				//cout<<"l:"<<l<<"R:"<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<"\n"; 
			}
			else a[r]-=a[l]; 
			l++;
		}
		else if(a[l]>a[r]){
			if(s[l]!=s[r]){
				ans+=a[r];
				a[l]-=a[r];
				//cout<<"l:"<<l<<"R:"<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<"\n"; 
			}
			else a[l]-=a[r];
			r--;
		}
		else if(a[l]==a[r]){
			if(s[l]!=s[r]){
				ans+=a[r];
				//cout<<"l:"<<l<<"R:"<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<"\n"; 
			}
			r--;l++;
		}
	}
	cout<<ans;
} 
