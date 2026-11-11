#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],i=1,j,ans=0;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]<a[j]) {
				a[j]-=a[i];
				i++;
			}
			else if(a[i]>a[j]) {
				a[i]-=a[j];
				i--;
			}
			
			else i++,j--;
		}
		else {
			if(a[i]<a[j]) {
				a[j]-=a[i];
				ans+=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				ans+=a[j];
				j--;
			}
			else {
				ans+=a[i];
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
