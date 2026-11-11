#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],c[N],ans;
void dfs(int i){
	if(i==n+1){
		int cnt=0;
		for(int j=1;j<=n;j++)cnt+=c[j];
		if(cnt!=m)return;
		int sum=0,ok=0;
		for(int j=1;j<=n;j++){
			if(!ok&&c[j])sum=a[j],ok=1;
			else if(c[j])sum&=a[j];
		}
		ans=max(ans,sum);
		return;
	}
	c[i]=0;
	dfs(i+1);
	c[i]=1;
	dfs(i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mx=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	if(n<=20){
		dfs(1);
		printf("%d\n",ans);
	}else{
		if(m==1)printf("%d\n",mx);
		else if(m==n){
			int g=a[1];
			for(int i=2;i<=n;i++)g&=a[i];
			printf("%d\n",g);
		}else if(m==2){
			int f=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)f=max(f,a[i]&a[j]);
			printf("%d\n",f);			
		}else{
			sort(a+1,a+n+1);
			int f=a[n];
			for(int i=n-1;i>=n-m+1;i--)
				f&=a[i];
			printf("%d\n",f);
		}
	}
}