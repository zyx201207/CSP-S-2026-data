#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],ans,mx;
int mc(int m,int ans,int cnt){
	if(1==m)return ans;	
	int ansj,mx;
	for(int i=cnt+1;i<=n-m+1;i++){
		ansj=mc(m-1,(ans&a[cnt]),i+1);
		cout<<ansj<<" ";
		mx=max(mx,ansj);
	}return mx;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==n){
		for(int i=1;i<=n;i++){
			cin>>a[i];	
			ans=ans&a[i];
		}cout<<ans;
		return 0;
	}if(m==2){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				mx=max(mx,ans);
			}
		}cout<<mx;
		return 0;
	}if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}cout<<mx;
		return 0;
		
	}for(int i=1;i<=n-m+1;i++){
		ans=mc(m,a[i],i);
		mx=max(mx,ans);
	}cout<<mx;
}
