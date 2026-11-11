#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100001],b[100001],c[100001],l=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int ju=1;ju<=n;ju++)
	{
		l=0;
		for(int i=ju;i<=n;i++)b[i]=0;
		for(int i=ju;i<=n;i++){
			l++;
			b[l]=a[i];
			for(int j=1;j<=l;j++){
				if(b[j]==a[i]){
					for(int k=j+1;k<=l;k++){
						b[k]=0;
					}
					l=j;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=l;j++){
				if(b[j]==i){
					c[i]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
	