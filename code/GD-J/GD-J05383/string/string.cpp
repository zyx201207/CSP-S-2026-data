#include<bits/stdc++.h>
using namespace std;
struct hwzf{
	long long m;
	string s;
}a[200005];
unsigned long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for (long long i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
	}long long l=1,r=n;
	while (l<=r){
		if (a[l].s!=a[r].s){
			if (a[l].m==a[r].m) ans+=a[r].m;
			int t=a[r].m;
			while (t<a[l].m){
				if (a[l].s!=a[r].s){
					ans+=a[r].m;
				}r--;
				t+=a[r].m;
			}ans+=(t-a[l].m);
		}if (a[l].s==a[r].s){
			int t=a[r].m;
			while (t<a[l].m){
				if (a[l].s!=a[r].s){
					ans+=a[r].m;
				}r--;
				t+=a[r].m;
			}if (a[l].s!=a[r].s) ans+=(t-a[l].m);
		}l++;
	}cout<<ans;
}
