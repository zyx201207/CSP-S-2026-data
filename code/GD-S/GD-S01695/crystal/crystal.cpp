#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N=5e5+9;
int n,m,a[N],q[N],ans=1;
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]+a[i];
	}
	
	if(n<=5000){
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++){
			q[i]=q[i-1]+a[i];
		}
		
		for(int r=1;r<=n;r++){
			for(int l=1;l<=r;l++){
				if((r-l+1)*a[r]-(q[r]-q[l-1])<=m){
					ans=max(ans,r-l+1);
				}
			}
		}
		
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++){
			q[i]=q[i-1]+a[i];
			//cout<<a[i]<<" "<<q[i]<<"\n";
		}
		
		for(int r1=1;r1<=n;r1++){//ÓÒ¶Ëµã 
			int ans1=1;
			int l=1,r=r1;
			int mid=0;//×ó¶Ëµã 
			while(l<=r){
				mid=(l+r)/2;
				if(q[r1]-q[mid-1] < -m+(r1-mid+1)*a[r1]){
					l=mid+1;
					//cout<<1;
				}
				else if(q[r1]-q[mid-1] > -m+(r1-mid+1)*a[r1]){
					ans1=(ans1,r1-mid+1);
					r=mid-1;
					//cout<<2;
				}
				else if(q[r1]-q[mid-1] == -m+(r1-mid+1)*a[r1]){
					ans=max(ans,r1-l+1);
					break;
				}
			}
			ans=max(ans,ans1);
		}
		
		cout<<ans;
	}
	
	return 0;
} 
