#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],b[500005];
int l,r,l1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	l=1;
	l1=1;
	r=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=l;i<=r;i++){
		for(int j=l;j<=r;j++)b[i]=a[i];
		for(int j=l+2;j<=r+1;j++){
			for(int p=l;p<j-1;p++){
				if(b[p]==b[j-1]){
					for(int k=p;k<j-1;k++){
						b[k]=0;
					}
					break;
				}
			}
			for(int p=l;p<=r;p++){
				if(b[p]==0){
					for(int k=p+1;k<=r;k++){
						b[k-1]=b[k];
					}
					p--;
					r--;
				}
			}
		}
		for(int j=l;j<=r;j++){
			ans[b[j]]++;
		}
		l=l1;
		r=n;
		l++;
		l1++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
