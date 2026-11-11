//GZ-J00318 贵阳中天中学 吴竣驰 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],k[N],ans[N],r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			k[j]=0;
		}
		for(int j=1;j<=n;j++){
			k[r]=a[j+r-1];
			r++;
			for(int l=1;l<=n;l++){
				if(a[l]==k[r]){
					for(int p=l;p<=n;p++){
						k[p]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(k[i]!=0){
				ans[k[i]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]!=0){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
