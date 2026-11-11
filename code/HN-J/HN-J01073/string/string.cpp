#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lgl long long
using namespace std;
const int  N=2e5+5;
lgl n,m,k;
lgl a[N];
lgl ans;
char c[N];

//aabbeef
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>a[i]>>c[i];
	}
	lgl lastl=0,lastr=0;
	for(lgl l=1,r=n;l<r;){
	//	cout<<lastl<<' '<<lastr<<' '<<ans<<' '<<l<<' '<<r<<'\n';

		if(a[l]<lastl){
			if(c[l]!=c[r])ans+=a[l];
			lastl-=a[l];
			l++;
			continue;
		}
		if(a[r]<lastr){
			if(c[l]!=c[r])ans+=a[r];
			lastr-=a[r];
			r--;
			continue;
		}
		if(lastl){
			if(c[l]!=c[r])ans+=lastl;
			lgl ll=a[l]-lastl;
			lastl=0;
			r--;
			if(c[l]!=c[r]){
				if(ll<a[r]){
					ans+=ll;
					lastl=a[r]-ll;
					l++;
				}else if(ll>a[r]){
					ans+=a[r];
					lastr=ll-a[r];
					r--;
				}else ans+=ll,l++,r--;
			}else{
				if(ll<a[r]){
					lastl=a[r]-ll;
					l++;
				}else if(ll>a[r]){
					lastr=ll-a[r];
					r--;
				}else l++,r--;
			}
		}
		else if(lastr){
			if(c[l]!=c[r])ans+=lastr;
			lgl rr=a[r]-lastr;
			lastr=0;
			l++;
			if(c[l]!=c[r]){
				if(rr<a[l]){
					ans+=rr;
					lastr=a[l]-rr;
					r--;
				}else if(rr>a[l]){
					ans+=a[l];
					lastl=rr-a[l];
					l++;
				}else ans+=rr, l++,r--;
			}else{
				if(rr<a[l]){
					lastr=a[l]-rr;
					r--;
				}else if(rr>a[l]){
					lastl=rr-a[l];
					l++;
				}else l++,r--;
			}
		}else {
			if(c[l]!=c[r]){
				if(a[l]>a[r]){
					lastr=a[l]-a[r];
					ans+=a[r];
					r--;
				}else if(a[r]>a[l]){
					lastl=a[r]-a[l];
					ans+=a[l];
					l++; 
				}else {
					ans+=a[l];
					l++,r--;
				}
			}else {
				if(a[l]>a[r])lastr=a[l]-a[r],r--;
				else if(a[r]>a[l])lastl=a[r]-a[l],l++;
				else l++,r--;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
//考虑维护两个变量维护左边和右边还需补足多少，双指针模拟即可，注意到l==r时不需要改，还剩多少都没用了，ans不用增加，直接退出 
