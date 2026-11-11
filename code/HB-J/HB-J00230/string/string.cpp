#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long cha,l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i] >> c[i];
	l=0;
	r=n+1;
	while(true){
		if(cha==0){
			l++;r--;
			if(l>=r)break;
			cha=a[l]-a[r];
			if(c[l]!=c[r])ans+=min(a[l],a[r]);
		}
		else if(cha>0){
			r--;
			if(l==r)break;
			if(c[l]!=c[r]){
				if(cha-a[r]>0)ans+=a[r];
				else ans+=cha;
			}
			cha-=a[r];
		}
		else{
			l++;
			if(l==r)break;
			if(c[l]!=c[r]){
				if(cha+a[l]<0)ans+=a[l];
				else ans-=cha;
			}
			cha+=a[l];
		}
	}
	cout << ans;
	return 0;
}
