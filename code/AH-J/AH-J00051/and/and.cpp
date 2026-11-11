#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010],b[200010],c[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	
	if(n>20&&m==2){
		cin>>a[1];
	for(int i=2;i<=n;i++){
	cin>>a[i];
	//c[i]=a[i];
	c[i-1]=a[i]&a[i-1];
	}

	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			b[j]=max(max(c[j],c[j+1]),a[i]&a[i+j-1]);
			}
			for(int j=1;j<=n-i+1;j++)c[j]=b[j];
		}
		
		cout<<c[2];
		return 0;
		}
		
		
	if(n>20&&m==1){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
		}
		
		
	if(n>20&&m==n){
		long long ooo=pow(2,31)-1;
		int p=0,ans=ooo;
		for(int i=1;i<=n;i++)cin>>p,ans&=p;
		cout<<ans;
		return 0;
		}
		
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	int f[m+2][2],ans=0;
	f[0][1]=a[1];
	f[m+1][0]=n+1;
	for(int i=1;i<=m;i++)f[i][0]=i,f[i][1]=f[i-1][1]&a[f[i][0]];
	while(f[1][0]<=n-m+1){
		
		if(f[m][1]>ans)ans=f[m][1];
		if(f[1][0]==n-m+1){
			break;
		}
		f[m][0]++;
		for(int j=m;j>=1;j--){
			if(f[j][0]>n-m+j){
				f[j-1][0]++;
				for(int l=j;l<=m;l++){
					f[l][0]=f[l-1][0]+1;
					}
				}
			}
			f[1][1]=a[f[1][0]];
		for(int i=2;i<=m;i++)f[i][1]=f[i-1][1]&a[f[i][0]];
		
		}
		
		cout<<ans;
		
	
		
return 0;
}
