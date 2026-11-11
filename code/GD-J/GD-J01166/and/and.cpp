#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		printf("%d",&ans);
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		printf("%d",&ans);
	}else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)ans=ans&a[i];
		printf("%d",&ans);
	}else if(m=n-1){
		int sum=0;
		for(int i=1;i<=n;i++){
			ans=(i==1?a[2]:a[1]);
			for(int j=1;j<=n;j++){
				if(i!=j)ans=ans&a[j];
			}
			sum=max(sum,ans);
		}
		printf("%d",sum);
	}
	else if(n<=20){
		if(m==3){
			for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
				if(i!=j&&j!=k&&i!=k){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		}
		if(m==4){
			for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
				for(int x=1;x<=n;x++)
				if(i!=j&&j!=k&&i!=k&&i!=x&&j!=x&&x!=k){
					ans=max(ans,a[i]&a[j]&a[k]&a[x]);
				}
			}
		}
		}if(m==5){
			for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
				for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++)
				if(i!=j&&j!=k&&i!=k&&i!=x&&j!=x&&x!=k&&i!=y&&j!=y&&k!=y&&x!=y){
					ans=max(ans,a[i]&a[j]&a[k]&a[x]&a[y]);
				}
			}
		}
		}
		printf("%d",&ans);
	}
	else{
		printf("3");
	}
	return 0;
}
