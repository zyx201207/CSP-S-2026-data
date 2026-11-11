#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],l1,l2,r1,r2,ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	l1=1,l2=1;
	r1=n,r2=a[n];
	while(l1<r1){
		if(c[l1]!=c[r1]) ans+=min(a[l1]-l2+1,r2);
		if(a[l1]-l2+1<r2){
			r2-=a[l1]-l2+1;
			l1++;
			l2=1;
			while(r2<0){
				r2+=a[--r1];
				if(c[l1]!=c[r1]) ans+=min(a[r1],l2);
			}
			while(l2>a[l1]){
				l2-=a[++l1];
				if(c[l1]!=c[r1]) ans+=min(a[l1],a[r1]-r2+1);
			}
		}
		else if(a[l1]-l2+1>r2){
			l2+=r2;
			r1--;
			r2=a[r1];
			while(r2<0){
				r2+=a[--r1];
				if(c[l1]!=c[r1]) ans+=min(a[r1],l2);
			}
			while(l2>a[l1]){
				l2-=a[++l1];
				if(c[l1]!=c[r1]) ans+=min(a[l1],a[r1]-r2+1);
			}
		}
		else{
			l1++,r1--;
			l2=1,r2=a[r1];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//T2
