//GZ-J00034，邵葛锦华，贵阳市观山湖区外国语实验中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
	}
		cout<<ans;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
					
				}
			}
		}
		cout<<ans;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
