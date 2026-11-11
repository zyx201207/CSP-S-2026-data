#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500009],nd,nw;
int cnt,ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	nd=a[n]-a[1];cnt=1;
	for(int i=2;i<=n;i++){
		nd+=a[n]-a[i];
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			ans=max(ans,cnt);
			cnt=1;
		}
	}
	//cout<<n<<" "<<m<<" "<<ans<<" "<<nd<<" "<<id<<endl;
	if(m==0) cout<<ans;
	else if(n>5000){
		if(nd<=m) ans=n;
		else{
			for(int i=n-1;i>=1;i--){
				nd-=i*(a[i+1]-a[i]);
				if(nd<=m){
					ans=max(ans,i);
					break;
				}/*a[1->ans] so it cannot AC*/
			}
		}
		cout<<ans;
	}else{
		for(int j=1;j<=n;j++){
			nd=0;
			for(int i=j+1;i<=n;i++){
				nd+=(i-j)*(a[i]-a[i-1]);
				if(i==n) fl=1;
				if(nd>m){
					ans=max(ans,i-j);
					break;
				}
			}
			if(fl) break;
		}
		cout<<ans;
	}
	return 0;
}
