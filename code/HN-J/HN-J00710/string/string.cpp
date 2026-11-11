#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],l,r,la,ra,ans,m;
char c[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;la=1;ra=a[n];
	while(l<r||(l==r&&la<ra)){
		
		m=min(a[l],a[r]);
		
		if(l<r&&m!=0){
			la+=m;ra-=m;
			if(c[l]!=c[r])ans+=m;
		}else{
			la++;ra--;
			if(c[l]!=c[r])ans++;
		}
		long long ll=l;
		if(la>a[l]){
			la-=a[l];a[r]-=m;
			l++;
		}
		if(ra<1){
			a[ll]-=m;
			ra+=a[r];
			r--;
		}
	}
	cout<<ans;

	return 0;
} 


