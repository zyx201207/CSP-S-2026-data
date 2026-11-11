#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200001],o,l=0,ans=0;
char b[200001],p;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	o=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=o;i++){
		int u=a[i];
		if(l!=0){
			if(p!=b[i]){
				if(u<=l){
					ans=ans+u;
					l=l-u;
					continue;
				}
				else{
					ans=ans+l;
					u=u-l;
					l=0;
				}
			}
			if(p==b[i]){
				if(u<=l){
					l=l-u;
					continue;
				}
				else{
					u=u-l;
					l=0;
				}
			}
		}
		for(;;){
			if(a[o]<=u&&o>i){
				if(b[o]!=b[i]) ans=ans+a[o];
				u=u-a[o],o--;
			}
			else break;
		}
		l=a[o],p=b[o];
		o--;
		if(p!=b[i]){
			ans=ans+u;
			l=l-u;
		}
		else l=l-u;
	}
	cout<<ans;
}
