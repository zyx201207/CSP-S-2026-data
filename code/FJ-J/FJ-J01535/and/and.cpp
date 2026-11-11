#include <iostream>
using namespace std;
int n,m,a[100005],ans,d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(m==1){
			ans=max(ans,a[i]);
		}else if(m==n){
			d=a[i];
			ans=d&ans;
		}else if(m==2){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;	
	return 0;
}
