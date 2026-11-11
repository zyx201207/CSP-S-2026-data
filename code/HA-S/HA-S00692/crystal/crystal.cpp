#include<bits/stdc++.h>
using namespace std;
int n,m,h=1;
int a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=i,z=1;
		for(int j=1;j<=n;j--){
			if(b[r]-b[l]==m) break;
			if(b[l]==1&&b[r+1]-b[l]<=m){
				r++;z++;
			}else if(b[l]==1&&b[r+1]-b[l]>m){
				break;
			}else{
				if(b[r]==n&&b[r]-b[l-1]<=m){
					l--;z++;
				}else if(b[r]==n&&b[r]-b[l-1]>m){
					break;
				}else{
					if(b[r+1]-b[l]>m&&b[r]-b[l-1]<=m){
						l--;z++;
					}else if(b[r+1]-b[l]<=m){
						r++;z++;
					}else{
						break;
					}
				}
			}
		}
		h=max(h,z);
	}
	cout<<"is"<<h<<" ";
	return 0;
}