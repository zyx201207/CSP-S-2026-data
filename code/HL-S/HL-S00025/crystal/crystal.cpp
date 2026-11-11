#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int N=5e5+10;

ll a[N],s[N];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int i=1,j=1,ma=0;
	ll sum=0;
	for (;j<=n;j++)  {
        sum+=(j-i)*(a[j]-a[j-1]);
        if (sum<=m) {
            ma=max(ma,j-i+1);
            continue;
        }
        while(i<=j && sum>m) sum-=a[j]-a[i],i++;
        ma=max(ma,j-i+1);
	}
	cout << ma;
	return 0;
}
