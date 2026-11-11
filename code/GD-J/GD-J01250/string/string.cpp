#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],s[N],l=1,r,ans;
char c[N];
int fd(int x){
	int l=1,r=n,res=0;
	while(l<=r){
		int mid=l+r>>1;
		if(s[mid]>=x)res=mid,r=mid-1;
		else l=mid+1; 
	}
	return res; 
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],s[i]=s[i-1]+a[i];
	r=s[n];
	while(l<r){
		int tl=fd(l),tr=fd(r);
		if(tl!=tr){
			int ls=s[tl]-l+1,rs=r-s[tr-1];
			int mi=min(ls,rs);
			if(c[tl]!=c[tr])ans+=mi;
			l+=mi,r-=mi;
		}else break;
	}
	cout<<ans;
}
