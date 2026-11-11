#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;
int a[200010];
char c[200010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int r=0,ll=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
	}
	ll=r;
	bool keep=0;
	int left=0;
	int ans=0,l=0,findr=n,right=ll;
	for(int i=1;i<=n;i++){
		int rr=l+a[i],now=l+1;
		if(rr>ll/2)rr=ll/2;
		if(now>ll/2)break;
		if(l>rr){
			break;
		}
		while(1){
			if(!keep)left=right-a[findr]+1;
			keep=0;
			if(left<(ll+1)/2+1)left=(ll+1)/2+1;
			if(left>right||i>=findr){
				break;
			}
			if(c[i]!=c[findr]){
				ans+=min(rr-now+1,right-left+1);
			} 
			if(right-left+1<=rr-now+1){
				now+=right-left+1;
			}else{
				right-=rr-now+1;
				keep=1;
				break;
			}
			findr--;
			right=left-1;
			if(now>rr)break;
		}
		l=rr;
	}
	cout<<ans<<endl;
	return 0;
} 
