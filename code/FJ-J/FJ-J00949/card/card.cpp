#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],c[300005],d[300005],top=1;

int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		top=1;
		for(int j=1;j<=m;j++)b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				d[top]=a[j];
				b[a[j]]=top;
				top++;
			}
			else {
				for(int k=b[a[j]]+1;k<top;k++)b[d[k]] =0;
				top=b[a[j]]+1;
			}
		}
		for(int j=1;j<top;j++){
			if(b[d[j]]!=0){
				c[d[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
