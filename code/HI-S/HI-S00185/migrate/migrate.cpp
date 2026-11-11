#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],b[2000005],o;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			for(int k=2;k<=n;k++){
				b[k-1]=abs(a[k-1]-a[k]);
			}
			for(int k=1;k<=n-1;k++){
				cout<<b[k]<<" ";
				o=0;
				if(b[k]>d){
					for(int l=k;l<=n;l++){
						a[l]=0;
						b[l]=0;
						o++;
					}
					n-=o;
				}
			}
		}
	}
	return 0;
}

