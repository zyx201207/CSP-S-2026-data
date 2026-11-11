#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200007],s[200007];;
char c[200007];
int l=1,r,lo=1,hi,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;hi=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=s[i-1]+a[i];
	}
	r=s[n];
//	cerr<<l<<" "<<r<<" "<<lo<<" "<<hi<<" "<<ans<<"\n";
	while(l<r&&lo<hi){
		if(s[lo]-l+1>=r-s[hi-1]){
			int num=s[lo]-l+1;
//			cout<<num<<"\n";
			while(num>0){
				if(num<a[hi]){
					if(c[hi]!=c[lo])ans+=num;
					r-=num;
					num-=num;
				}else if(r>s[hi]&&r<s[hi+1]){
					num-=r-s[hi];
					if(c[hi]!=c[lo])ans+=r-s[hi];
					r=s[hi];
				}else{
					r-=a[hi];
					num-=a[hi];
					if(c[hi]!=c[lo])ans+=a[hi];
					hi--;
				}
//				cerr<<l<<" "<<r<<" "<<lo<<" "<<hi<<" "<<num<<" "<<ans<<"\n";
			}
			l=s[lo];
			lo++;
		}
		else{
			int num=r-s[hi-1];
//			cout<<num<<"\n";
			while(num>0){
				if(num<a[lo]){
					if(c[hi]!=c[lo])ans+=num;
					l+=num;
					num-=num;
				}else if(r<s[lo]&&r>s[lo-1]){
					num-=s[lo]-r;
					if(c[hi]!=c[lo])ans+=s[lo]-l;
					l=s[lo];
				}else{
					l+=a[lo];
					num-=a[lo];
					if(c[hi]!=c[lo])ans+=a[lo];
					lo++;
				}
//				cerr<<l<<" "<<r<<" "<<lo<<" "<<hi<<" "<<num<<" "<<ans<<"\n";
			}
			r=s[hi];
			hi--;
		}
	}
	cout<<ans;
	return 0;
}
