#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005];
int know[1000005];
bool bo[1000005];
int ans[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			know[j]=a[j];
			if(bo[a[j]]){
				for(int p=j-1;p>0;p--){
					if(know[p]==a[j]){
						know[p]=0;
						break;
					}
					know[p]=0;
					bo[p]=0;
				}
			}
			bo[a[j]]=1;
		}
		cout<<endl;
		for(int j=i;j<=n;j++){
			ans[know[j]]++;
			bo[j]=0;
			know[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	} 
	return 0;
}
