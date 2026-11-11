#include<bits/stdc++.h>
using namespace std;
long long n,a,lst,mid,sm,ar[2000005],r,l,ans;
char c,s[2000005];
long long sc(long long pos){
	long long res=upper_bound(ar+1,ar+1+n,pos)-ar-1;
	return res;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		ar[i]=lst+1;
		s[i]=c;
		lst+=a;
		sm+=a;
	}
	ar[n+1]=lst+1;
	mid=(sm+1)/2;
	l=mid;
	while(l){
		r=sm-l+1;
		int lp=sc(l),rp=sc(r),dn=l-ar[lp]+1,up=ar[rp+1]-r;
		//cout<<l<<' '<<r<<' '<<lp<<' '<<rp<<' '<<dn<<' '<<up<<endl;
		if(s[lp]!=s[rp])ans+=min(dn,up);
		l-=min(dn,up),r+=min(dn,up);
	}
	cout<<ans;
}
