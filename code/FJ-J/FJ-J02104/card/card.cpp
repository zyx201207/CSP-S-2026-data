#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i]; c[i]=a[i];
	}
	if(n<=5){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k>=1;k--){
					if(c[j]==c[k]){
						for(int l=k;l<=j;l++) a[l]=0;
					} 
				}
				int ans=0;
				for(int k=1;k<=n;k++){
					if(a[k]==i) ans++;
				}
				
				cout<<ans<<' ';
			}
		}
		return 0;
	}
	int b[500005];
	a[0]=a[1];
	b[0]=0;
	int lst=1;
	for(int i=1;i<=m;i++){
		int j;
		for(j=lst+1;a[j]==a[j-1];j++); b[i]=j+1;
		cout<<b[i]-2<<' ';
		lst=j;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
