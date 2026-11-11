#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],top,o[500005],num[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i]; 
	for(int i=0;i<n;i++){
		top=0;
		for(int j=i;j<n;j++){
			num[top++]=a[j];
			for(int k=0;k<top-1;k++){
				if(num[k]==a[j]){
					for(int l=k;l<top-1;l++){
						num[l]=0;
					}
				}
			}
		}
		for(int j=0;j<top;j++){
			o[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<" ";
	}
	return 0;
}
