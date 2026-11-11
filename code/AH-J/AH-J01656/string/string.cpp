#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2*1e5+5;
int n,a[MAXN],len,ans;
int d[MAXN];
char c[MAXN];

int sure(int al){
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l)/2;
		if(d[mid-1]<al && d[mid]>=al){
			return mid;
		}else if(al<d[mid]){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		d[i]=d[i-1]+a[i];
	}
	int l=1,ii=1;
	while(l<=len/2){
		int al=len+1-l;
		int jj=sure(al);	
		if(c[ii]==c[jj] && a[ii]+a[jj]!=len){
			ans+=abs(a[ii]-a[jj]);
		}else if(a[ii]+a[jj]==len){
			ans=0;
			break;
		}else{
			ans+=max(a[ii],a[jj]);
		}
		l+=max(a[ii],a[jj]);
		ii=sure(l);
	}
	cout<<ans;
	return 0;
}
