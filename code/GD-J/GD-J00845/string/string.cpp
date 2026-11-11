#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
char c[maxn];
int a[maxn],l,r,sa,sb,n,mx = 0;
long long ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx = max(mx,a[i]);
	}
	l = 1,r = n,sa = a[1],sb = a[n];
	while(l<r){
		if(sa==sb){
			ans+=sa*(c[l]!=c[r]);
			l++,r--;
			sa = a[l],sb = a[r];
		}
		else if(sa<sb){
			ans+=sa*(c[l]!=c[r]);
			l++,sb-=sa;
			sa = a[l];
		}
		else{
			ans+=sb*(c[l]!=c[r]);
			sa-=sb;
			r--;
			sb = a[r];
		}
//		cout<<sa<<c[l]<<" "<<sb<<c[r]<<"\n";
	}
	cout<<ans;
	return 0;
} 
