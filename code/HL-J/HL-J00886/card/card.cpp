
#include<bits/stdc++.h>
using namespace std;
const N=2e5+10;
int n,m ,a[N];
bool(int x,int y)
return x>y;
signed main(){
	freopen("and.in","r","std.in");
	freopen("and.out","w","std.out");
    cin >> n>>m;
	for(int i=1;i<=n;i++)
	{
		cout <<a[i];
		}
	sort(a+1;a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
	
			ans&=a[i];
			
	}
	cout << ans;
	return 0;
}