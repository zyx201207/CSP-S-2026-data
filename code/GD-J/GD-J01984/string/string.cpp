#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,l,r,ans,sum[N],a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum[i]=sum[i-1]+a[i];
		if(a[i]!=1) f=0;
	}
	if(n==1||f==1){
		cout<<0;
	}
	if(sum[n]&1){
		int mid=sum[n]/2+1;
		int idxl=upper_bound(a+1,a+n+1,mid)-a-1,idxr=upper_bound(a+1,a+n+1,mid)-a;
		l=mid-1,r=mid+1;
		while(l>=1&&r<=sum[n]){
			if(s[idxl]==s[idxr]){
				l-=min(a[idxl],a[idxr]);
				r+=min(a[idxl],a[idxr]);
				if(a[idxl]<a[idxr]){
					idxl--;
				}
				else if(a[idxl]>a[idxr]){
					idxr++;
				}
				else{
					idxl--,idxr++;
				}
			}
			else{
				ans++;
				l--,r++;
			}
		} 
	}
	else{
		int mid=sum[n]/2+1;
		int idxl=upper_bound(a+1,a+n+1,mid)-a-1,idxr=upper_bound(a+1,a+n+1,mid)-a;
		l=mid,r=mid+1;
		while(l>=1&&r<=sum[n]){
			if(s[idxl]==s[idxr]){
				l-=min(a[idxl],a[idxr])+1;
				r+=min(a[idxl],a[idxr])+1;
				if(a[idxl]<a[idxr]){
					idxl--;
				}
				else if(a[idxl]>a[idxr]){
					idxr++;
				}
				else{
					idxl--,idxr++;
				}
			}
			else{
				ans++;
				l--,r++;
			}
		} 
	}
	cout<<ans;
	return 0;
}
