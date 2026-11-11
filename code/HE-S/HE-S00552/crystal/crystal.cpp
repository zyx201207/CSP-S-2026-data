#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int s;
	cin>>n>>m;
	int a[10000000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	int ave=(s+m)/2;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i+1]){
			int o=a[i];
			a[i]=a[i+1];
			a[i+1]=o;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m==0){
			break;
		}
		if(a[i]<ave){
			m-=ave-a[i];
			ans++;	
		}
	}
	cout<<ans;
	return 0;
	
}
