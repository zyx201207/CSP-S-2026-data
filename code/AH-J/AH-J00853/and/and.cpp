#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
typedef long long ll;
ll n,m,a[N],he[N],he1[N],mx=-1,ans=-1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    he[0]=pow(2,30);
    he1[n+1]=pow(2,30);
    for(int i=1;i<=n;i++){
		cin>>a[i];
		he[i]=he[i-1]&a[i];
		mx=max(mx,a[i]);
	}
	for(int i=n;i>=1;i--){
		he[i]=he[i+1]&a[i];
	}
	if(m==1){
	   cout<<mx;
	   return 0;
    }
    if(m==2){    
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,ll(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}	
    if(m==n-1){
	   for(int i=1;i<=n;i++){
		   ans=max(ans,he[i-1]&he1[i+1]);
	   }
	   cout<<ans;
	   return 0;
   }
   cout<<0;
    return 0;
}
