#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>> n;
	for (int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n,q=0,ans=0,k,o,w,l=0;
	while (1){
	if (i==j and !q or j<i) break;
	if (i==j) l++;
	if(l==2) break;
		if (q) {
		w=q;
			if (o==1) {if(c[k]!=c[j])  
			ans+=min(q,a[j]);
			q=abs(a[k]-a[j]);
			if (q) {
			if (w>a[j]) o=1;
			else k=j,o=2;
			}
			
			j--;
		
		
		}
		else {
			if(c[i]!=c[k])  
			ans+=min(a[i],a[k]);
			q=abs(a[i]-a[k]);
			if (q) {
			if (w>a[k]) k=i,o=1;
			}
			i++;

			
		}
		}
		else if(c[i]!=c[j])  
			ans+=min(a[i],a[j]);
			q=abs(a[i]-a[j]);
			if (q) {
			if (a[i]>a[j]) k=i,o=1;
			else k=j,o=2;
			}
			i++;
			j--;
		

	}
	cout<<ans;
	return 0;
}
