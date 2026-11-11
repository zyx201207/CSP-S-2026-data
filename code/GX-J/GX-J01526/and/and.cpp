#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<a[1]<<endl;
	return 0;
}
