#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int b[500005],mn = INT_MAX,c[500005],ans;
bool f = 1,con;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i = 1;i < n;i++){
		if(con){
			con = 0;
			continue;
		}
		b[i] = a[i+1]-a[i];
		if(a[i+1] == a[i]){
			f = 0;
			int l = i,r = n,mid,t = (a[i]<<1);
			while(l<=r){
				mid = l+((r-l)>>1);
				if(a[mid]>t) r = mid-1;
				else l = mid+1;
			}
			n++;
			for(int i = n;i >= r+2;i++) a[i] = a[i-1];
			a[r+1] = t;
			c[t] = max(c[t],c[a[i]]+1);
			con=1; 
		}
		mn = min(mn,b[i-1]);
	}
	for(int i = 1;i<=300;i++){
		ans = max(ans,c[i]);
	}
	if(mn>m&&f) cout<<0;
	else cout<<ans;
	return 0;
}
