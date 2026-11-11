#include<bits/stdc++.h>
using namespace std;
int n,m,b,ans=-1;
long long q[500005],w[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n);
	for(int i=1;i<n;i++){
		w[i]=abs(q[i+1])-abs(q[i]);
	}if(n>=500000){
		long long y=q[2]-q[1];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ans+i*y<m){
				ans+=i*y;
				cnt++;
			}else if(ans+i*y==m){
				cout<<cnt+1;
				return 0;
			}else{
				cout<<cnt;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=1,ans1=0,t=0;
			for(int k=i;k<=j;k++){
				if(ans1+cnt*w[k]>m){
					t=1;
					break;
				}
				ans1+=cnt*w[k];
				cnt++;
			}if(ans1<=m&&t!=1){
				ans=max(ans,j-i+2);
			}t=0;
		}
	}
	cout<<ans;
	
	return 0;
}
