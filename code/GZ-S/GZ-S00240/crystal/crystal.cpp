//GZ-S00240 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long us=0;
		int j=i+1;
		while(us<=m&&j<=n){
			us+=a[j]-a[i];
			j++;
		}
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
}
