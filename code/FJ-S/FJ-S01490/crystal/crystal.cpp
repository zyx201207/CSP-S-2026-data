#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],qzh[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool xz=true;
	int dc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=dc){
			xz=false;
			break;
		}
	}
	if(xz==true){
		int w=dc;
		int ans=dc;
		int cnt=0;
		while(m&&cnt<n){
			if(m>=ans){
				cnt++;
				m-=ans;
			}else{
				cout<<cnt+1;
				return 0;
			}
			ans+=dc;
		}
		cout<<cnt;
		return 0;
	}
	int mx=INT_MIN;
	for(int i=1;i<=n;i++){
		int ans=i-1;
		while(m&&ans>0){
			int dq=a[i]-a[ans];
			if(m>=dq){
				m-=dq;
			}else{
				break;
			}
			ans--;
		}
		if(i-ans+1>mx)mx=i-ans+1;
	}
	cout<<mx;
	return 0;
} 
