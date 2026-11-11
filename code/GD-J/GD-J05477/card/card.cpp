#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[500005],ans[300005];
int f[500005],fs;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=0; i<=n; i++){
		fs=0;
		for(int j=i+1; j<=n; j++){
			f[fs++]=a[j];
			for(int k=0; k<fs-1; k++)
				if(f[k]==f[fs-1]){
					fs=k+1;
					break;
				}
		}
		for(int j=0; j<fs; j++)ans[f[j]]++;
	}
//	cout<<ans[1];
	for(int i=1; i<=m; i++)cout<<ans[i]<<' ';
	return 0;
}
