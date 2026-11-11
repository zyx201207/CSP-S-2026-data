#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}return x*f;
}
int c,t;
int n,d,ns[2000005];
int l,r,mid,idx[2000005];
int dp[2000005][3],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	c=rd();t=rd();
	while(t--){
		n=rd();d=rd();
		ans=0;
//			cout<<t<<" ";
//			if(t==10)cout<<n<<"*\n";
		for(int i=1;i<=n;i++){
			ns[i]=rd();
//			if(t==10)ns[i]-=999999999999000000;
			l=1,r=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(ns[i]-ns[mid]<=d){
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			idx[i]=r+1;
			if(idx[i]==i){
				idx[i+1]=i;
				idx[i+2]=i;
			}else if(idx[i]+1==i){
				idx[i+1]=idx[i];
			}
			dp[i][0]=idx[idx[i]+2]-idx[idx[i]+1];
			dp[i][1]=0;
			dp[i][2]=idx[idx[i]+1]-idx[idx[i]];
			if(idx[idx[i]]+1<idx[idx[i]+1]){
				dp[i][0]+=dp[idx[i]][0];
				dp[i][1]+=dp[idx[i]][0];
				dp[i][2]+=dp[idx[i]][2];
			}else if(idx[idx[i]]+1==idx[idx[i]+1]){
				dp[i][0]+=dp[idx[i]][1];
				dp[i][1]+=dp[idx[i]][1];
				dp[i][2]+=dp[idx[i]][2];
			}else if(idx[idx[i]]==idx[idx[i]+1]&&idx[idx[i]+1]<idx[idx[i]+2]){
				dp[i][0]+=dp[idx[i]][2];
				dp[i][1]+=0;
				dp[i][2]+=0;
			}
//			if(t==10)cout<<dp[i][0]<<"*\n";
			ans+=dp[i][0];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
