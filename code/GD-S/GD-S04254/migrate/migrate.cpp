#include <bits/stdc++.h>
using namespace std;
int c,n1,n,m;
int a[10000005],b[10000005],d[100005];
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	cin>>c>>n1;
	for(int k=1;k<=n1;k++){
		int cnt=0,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i]-a[i-1];
			d[i]+=b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int sum=0;
				cnt=0;
				int cha=j-i;
				for(int l=i;l<=j-1;l++){
					if ((d[l+j]-d[l+i])<=m&&l-i>0&&l-j<=0){
						cnt++;
					}
				}
				if(cnt==2){
					ans++;
					cnt=0;
					sum=0;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			b[i]=0;
			a[i]=0;
		}
	}
	return 0;
} 
