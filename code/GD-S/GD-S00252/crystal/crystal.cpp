#include<bits/stdc++.h>
typedef  long long ll;
using namespace std;
int n;
ll m,s[500005],a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,mx=0,s=0;
	for(int r=2;r<=n;r++){
		s+=(a[r]-a[r-1])*(r-l);
		while(s>m){
			s-=(a[r]-a[l]);
			l++;
		}
		mx=max(mx,r-l+1);
	}
	cout<<mx;
}

