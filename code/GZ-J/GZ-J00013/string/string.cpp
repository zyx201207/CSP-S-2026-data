//GZ-J00013 ÎÄãüºÆ 
#include <bits/stdc++.h>
using namespace std;
long long n,a[200080],cnt=0,l,r,ans=0;
string s,s1;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		cin >> s1;
		s+=s1;
		cnt+=a[i];
	}
	l=1,r=n;
	while(l<r)
	{
		if(s[l-1]!=s[r-1]){
			if(a[l]>a[r]){
				ans+=min(a[r],a[l]);
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				ans+=min(a[r],a[l]);
				a[r]-=a[l];
				l++;
			}
			else{
				ans+=a[l];
				l++;
				r--;
			}
		}
		else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
