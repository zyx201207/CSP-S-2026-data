#include<bits/stdc++.h>
using namespace std;
int a[200010],flag[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		flag[i]=1;
	}
	for(int i=30;i>=0;i--){
		int s=0;
		int f[200010];
		for(int j=1;j<=n;j++)f[j]=flag[j];
		for(int j=1;j<=n;j++){
			if(flag[j]){
				if(a[j]&(1<<i)){
					s++;
				}else f[j]=0;
			}
		}
		if(s>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++)flag[j]=f[j];
		}
	}
	cout<<ans;
	return 0;
}
