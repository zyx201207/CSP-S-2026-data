#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200020],ans=1,imax;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    unsigned long long n,m;
    cin>>n>>m;
    for(unsigned long long i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]>ans) ans=a[i];
    }
    sort(a+1,a+1+n);
    for(unsigned long long i=n;i>=n-m+1;i--)
    ans=a[i]&ans;
	cout<<ans;
	fclose(stdin);
    return 0;
}
