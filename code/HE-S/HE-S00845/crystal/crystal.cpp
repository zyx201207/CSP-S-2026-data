#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			int x=a[i]-a[i-1];
			m-=(i-1)*x;
			if(m<0){
				cout<<c;
				return 0;
			}
			c++;
		}
		else c++;
	}
	cout<<c;
}
