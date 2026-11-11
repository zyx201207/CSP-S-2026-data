#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int a[maxn],deskz[maxn],ans[maxn];
int main()
{
	int n,m,out;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			out=a[j];
			if(deskz[out]==0){
				deskz[out]++;
			}
			if(deskz[out]==1){
				for(int o=1;o<=m;o++){
					deskz[o]=0;
				}
				deskz[out]++;
			}
		}
		for(int f=1;f<=m;f++){
			ans[f]+=deskz[f];
		}
		for(int r=1;r<=m;r++){
			deskz[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
