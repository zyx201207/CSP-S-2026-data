#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, a[200010];
	long long ans=0;
	char c[200010];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int s=1, e=n;
	while(s<e){
		if(s>=e)
			break;
		if(c[s]!=c[e]){
			if(a[s]<a[e]){
				ans+=a[s];
				a[e]-=a[s];
				a[s]=0;
				s++;
			}
			else if(a[s]>a[e]){
				ans+=a[e];
				a[s]-=a[e];
				a[e]=0;
				e--;
			}
			else if(a[s]==a[e]){
				ans+=a[s];
				a[s]=a[e]=0;
				s++;
				e--;
			}
		}
		if(s>=e)
			break;
		else if(c[s]==c[e]){
			if(a[s]<a[e]){
				a[e]-=a[s];
				a[s]=0;
				s++;
			}
			else if(a[s]>a[e]){
				a[s]-=a[e];
				a[e]=0;
				e--;
			}
			else if(a[s]==a[e]){
				a[s]=a[e]=0;
				s++;
				e--;
			}			
		}
		if(s>=e)
			break;
	}
	cout<<ans;
	return 0;
}
