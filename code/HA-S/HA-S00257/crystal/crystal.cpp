#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0;
int a[500009];
int pre[500009];
int check(int k){
	int l=1,r=k;
	while(l<r){
		int mid=(l+r)/2;
		int h=a[k]*(k-mid+1)-pre[k]+pre[mid-1];
		if(h<m){
			r=mid;
		}else if(h==m){
			return mid;
		}else{
			l=mid+1;
		}
	}return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=a[i]+pre[i-1];
	}for(int i=1;i<=n;i++){
		int l=check(i);
		ans=max(ans,i-l+1);
	}cout<<ans<<endl;
	return 0;
} 
//rp++
