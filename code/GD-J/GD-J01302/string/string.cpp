#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct f{
	char r;
	int s;
}a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].s>>a[i].r;
	for(int l=1,r=n;l<r;){
		if(a[l].r==a[r].r){
			if(a[l].s==a[r].s) l++,r--;
			else if(a[l].s>a[r].s)a[l].s-=a[r].s,r--;
			else a[r].s-=a[l].s,l++;
		}
		else {
			if(a[l].s==a[r].s) ans+=a[l].s,l++,r--;
			else if(a[l].s>a[r].s)ans+=a[r].s,a[l].s-=a[r].s,r--;
			else ans+=a[l].s,a[r].s-=a[l].s,l++;
		}
	}
	cout<<ans;
	return 0;
} 
