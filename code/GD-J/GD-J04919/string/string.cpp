#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
struct node{
	char dat;
	long long s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i].s>>a[i].dat;
	l = 1,r = n;
	while(l<r){
		if(a[l].dat==a[r].dat){
			if(a[l].s==a[r].s) l++,r--;
			else if(a[l].s>a[r].s) a[l].s -= a[r].s,r--;
			else a[r].s -= a[l].s,l++;
		}else{
			if(a[l].s==a[r].s) ans += a[l].s,l++,r--;
			else if(a[l].s>a[r].s) ans += a[r].s,a[l].s -= a[r].s,r--;
			else ans += a[l].s,a[r].s -= a[l].s,l++;
		}
	}cout<<ans;
	return 0;
}
