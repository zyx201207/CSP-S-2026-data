#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],x=1,y,an,ans;
bool f[200010],r=true;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=30;i>=0;i--){
		an=0;
		for(int j=1;j<=n;j++){
			if(!f[j]&&(a[j]&(1<<i))==(1<<i)){
				an++;
			}
		}
		if(an>=m){
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0){
					f[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			if(r){
				ans=a[i];
				r=false;
			}else{
				ans=ans&a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
