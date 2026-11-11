#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n;
ll ans,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	ll l=0,r=0;
	for(int i=1,j=n;i<j;){
		if(!l&&!r){
			if(c[i]==c[j]){
				if(a[i]==a[j]) continue;
				 else if(a[i]>a[j]) l=a[i]-a[j];
				  else r=a[j]-a[i];
			}
			else{
				if(a[i]==a[j]) ans+=a[i];
				 else if(a[i]>a[j]) l=a[i]-a[j],ans+=a[j];
				  else r=a[j]-a[i],ans+=a[i];
			}
		}
		else if(l){
			if(c[i]==c[j]){
				if(l==a[j]) l=r=0;
				 else if(l>a[j]) l-=a[j];
				  else r=a[j]-l,l=0;
			}
			 else{
			 	if(l==a[j]) ans+=l,l=r=0;
			 	 else if(l>a[j]) ans+=a[j],l-=a[j];
			 	  else ans+=l,r=a[j]-l,l=0;
			 }
		}
		else{
			if(c[i]==c[j]){
				if(r==a[i]) l=r=0;
				 else if(r>a[i]) r-=a[i];
				  else l=a[i]-r,r=0;
			}
			else{
			 	if(r==a[i]) ans+=r,l=r=0;
			 	 else if(r>a[i]) ans+=a[i],r-=a[i];
			 	  else ans+=r,l=a[i]-r,r=0;
			 }
		}
		
		if(l>0) j--;
		else if(r>0) i++;
		else i++,j--;
	}
	cout<<ans;
	return 0;
}

