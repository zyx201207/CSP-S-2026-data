#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1100000],b[1100000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(m==1){
			b[i]=max(b[i],a[i]);
		}else if(m==2){
			for(int j=1;j<=n;j++){
				if(i!=j){
					b[i]=max(b[i],a[i]&a[j]);
				}
			}		
		}else if(m==3){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j&&i!=k&&j!=k){
						b[i]=max(b[i],a[i]&a[j]&a[k]);
					}
				}	
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(ans<b[i]){
			ans=b[i];
		}
	}
	cout<<ans;
	return 0;
}
