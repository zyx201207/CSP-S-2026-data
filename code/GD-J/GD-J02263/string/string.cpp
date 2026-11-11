#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n,na,a[N],sum,l,r,ls,rs,ans,ne;
char c[N],nec;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>ne>>nec;
		sum+=ne;
		if(c[i-na-1]==nec){
			na++;
			a[i-na]+=ne;
		}
		else{
			a[i-na] = ne;
			c[i-na] = nec;
		}
	}
	n-=na;
	l = 0,r = n+1,l = 0,rs = 0;
	while(l<r){
		if(ls<=rs){
			l++;
			if(ls+a[l]>sum/2){
				ans+=abs(rs-ls);
				break;
			}
			if(c[l]!=c[r]){
				ans+=min(a[l],abs(ls-rs));
			}
			ls+=a[l];
		}
		else{
			r--;
			if(rs+a[r]>sum/2){
				ans+=abs(rs-ls);
				break;
			}
			if(c[l]!=c[r]){
				ans+=min(a[r],abs(rs-ls));
			}
			rs+=a[r];
		}
	}
	cout<<ans;
	return 0;
}

