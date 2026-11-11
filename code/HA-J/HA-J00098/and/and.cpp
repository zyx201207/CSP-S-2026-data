#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int m,n;
bool flag[200005];
long long ans=0,ans2=0,cnt;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	ans=a[1];
	for(int i=2;i<=n-m+1;i++){
		ans2=ans&a[i];
		flag[i]=1;
		int z=i;
		for(int k=1;k<=m;k++){
			for(int j=i+1;j<=n;j++){
				if(flag[j]==0&&ans&a[j]>ans2){
					ans2=ans&a[j];
					flag[j]=1;
					flag[z]=0;
					z=j;
				}
			}
			ans=ans2;
			int x=z;
			while(x==1&&x<=n){
				x++;
			}
			ans2=ans&a[x];
			flag[x]=1;
			z=x;
		}
		
		
	}
	
	cout<<ans;
	return 0;
}
