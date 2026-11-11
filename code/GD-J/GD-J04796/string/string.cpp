#include<bits/stdc++.h>
using namespace std;
long long n,q,h,a[200010];
long long ans=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	q=1;
	h=n;
	while(q<h){
		int tmp=min(a[q],a[h]);
		if(c[q]!=c[h]){
			ans+=tmp;
		}
		a[q]-=tmp;
		a[h]-=tmp;
		if(a[q]==0)
			q++;
		if(a[h]==0)
			h--;
	}
	cout<<ans;
	return 0;
}
