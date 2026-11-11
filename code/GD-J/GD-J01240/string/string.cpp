#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n; 
int a[N];
char b[N];
int pre[N];
int sum=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],sum+=a[i],pre[i]=pre[i-1]+a[i];
	int mid=(sum+1LL)/2,tmp=0,tmp_i=0;
	for(int i=1;i<=n;i++){
		tmp+=a[i];
		if(tmp>=mid){
			tmp_i=i;
			break;
		}
	}
	int cnt=0;
	if(sum%2==0){
		int l=tmp_i,r=tmp_i+(tmp==mid?1:0);
		int l_sum=mid-pre[l-1],r_sum=(l!=r?a[r]:a[l]-l_sum-2);
		while(l>=1 and r<=n){
			if(l_sum==0) l--,l_sum=a[l];
			if(r_sum==0) r++,r_sum=a[r];
			if(b[l]!=b[r]) cnt+=min(l_sum,r_sum);
			int cost=min(l_sum,r_sum);
			l_sum-=cost,r_sum-=cost;
		}
	}
	else{
		int l=tmp_i,r=tmp_i;
		int l_sum=mid-pre[l-1]-1,r_sum=a[tmp_i]-l_sum-1;
		while(l>=1 and r<=n){
			if(l_sum==0) l--,l_sum=a[l];
			if(r_sum==0) r++,r_sum=a[r];
			if(b[l]!=b[r]) cnt+=min(l_sum,r_sum);
			int cost=min(l_sum,r_sum);
			l_sum-=cost,r_sum-=cost;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
