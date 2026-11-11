#include<iostream>
#include<cstdio>
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0;
	cin>>n,m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<n;i++){
		for(int dp=0;dp<n;i++){
			int z[n];
			z[dp]=a[dp+i-1];
			for(int qp=0;qp<dp;qp++){
				if(z[dp]==z[qp]){
					for(;qp<dp;qp++){
						z[qp]=0;
					}
				}
			}
		}
		
		for(int jg=1;jg<=n;jg++){
				for(int sz=0;sz<n;sz++){
					if(z[sz]==jg){
						a[jg]=a[jg]+1;
					}
				}		
		}
	}
	for(int i=0;i<n;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
