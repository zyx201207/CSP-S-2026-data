#include<bits/stdc++.h>																
using namespace std;
long long m,ans,x,n,h,l=1,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=a[n];i++){
		x=0;
		if(i<a[1]) continue;        
		else{
			int y=n,h=0;
			for(int j=1;j<=n;j++){
				if(a[j]>i){
					y=j;
					break;
				}
			}
			if(a[n]==i) x++;
			for(int j=y-1;j>=1;j--){
				h+=i-a[j];
				x++;
				if(h>m){
					x--;
					break;
				}
			}
		}
		//cout<<i<<' '<<x<<endl;
		ans=max(ans,x);
	}
	//cout<<endl<<endl<<endl<<endl;
	cout<<ans;
	return 0;
}
