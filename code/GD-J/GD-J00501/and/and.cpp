#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[210000];
int c[30];

int top;
int ans=-1<<30;
void solve(int step,int sum){
	if(step==n+1){
		if(sum==0){
			int coutt=-1;
			for(int i=1;i<=n;i++){
				if(c[i]){
					if(coutt==-1){
						coutt=a[i];
					}
					else coutt=coutt&a[i];
				}
			}
			ans=max(ans,coutt);
		}
		return;
	}
	c[step]=1;
	solve(step+1,sum-1);
	c[step]=0;
	solve(step+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=20){
		solve(1,m);
		printf("%d",ans);
		return 0;
	}
	else if(n>20&&n<=2000){
		if(m==1){
			sort(a+1,a+n+1);
			printf("%d",a[n]);
			return 0; 
		}
		if(m==2){
			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j) ans=max(ans,a[i]&a[j]);
				}
			}
			printf("%d",ans);
			return 0;
		}
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i]; 
			}
			printf("%d",ans);
			return 0;
		}
	}
	
	return 0;
} 
