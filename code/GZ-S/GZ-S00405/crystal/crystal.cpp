//GZ-S00405 ·ë»¸î£ 
#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;return 0;
	}
	sort(a+1,a+n+1);
	int zhi=0;
	while(1){
		for(int i=1;i<=ans;i++){
			b[i]=a[i];
		}
		zhi=0;
		for(int i=1;i<=ans;i++){
			zhi=zhi+(b[ans]-b[i]);
		}
		if(zhi<m){
			ans++;
		}else{
			if(zhi==m&&ans+1<n&&a[ans+1]==b[ans]){
				ans++;
				continue;
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}
