#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],s,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=1;
	for(int i=29;i>=0;i--)
	{
		k=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]&(1<<i)&&b[j])k++;
		}
		if(k<m)continue;
		for(int j=1;j<=n;j++)
		{
			if(!(a[j]&(1<<i)))b[j]=0;
		}
		s+=(1<<i);
	}
	cout<<s;
	return 0;
}
