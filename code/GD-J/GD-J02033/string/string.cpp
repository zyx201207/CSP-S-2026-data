#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=2e5+5;
ll n,a[N],c[N],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char ct;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ct;
		c[i]=ct-'a';
	} 
	ll l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			ll de=min(a[l],a[r]);
			a[l]-=de;
			a[r]-=de;
			if(a[l]==0){
				l++;
			}else{
				r--;
			}
			ans+=de;
		}else{
			ll de=min(a[l],a[r]);
			a[l]-=de;
			a[r]-=de;
			if(a[l]==0){
				l++;
			}else{
				r--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
