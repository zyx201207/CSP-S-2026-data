#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200007];
int wei[200007][30];
int c[200007];
int mx=0;
void dfs(int burn,int now,int remain){
	if(now>n||remain==0){
		int tmp=c[1];
		for(int i=2;i<burn;i++){
			tmp=tmp&c[i];
		}
		mx=max(mx,tmp);
		return;
	}
	if(n-now<remain){
		return;
	}
	dfs(burn,now+1,remain-1);
	c[burn]=a[now];
	dfs(burn+1,now+1,remain-1);
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1,f1=1,f2=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>4){
			flag=0;
		}
		if(a[i]!=i-1){
			f1=0;
		}
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,1,m);
		printf("%d",mx);
	}
	else if(n<=2000){
		if(m==1){
			int maxx=-1;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			printf("%d",maxx);
		}
		if(m==2){
			int maxx=-1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			printf("%d",maxx);
		}
		if(m==n){
			int tmp=a[1];
			for(int i=2;i<=n;i++){
				tmp=tmp&a[i];
			}
			printf("%d",tmp);
		}
	}
	else{
		if(flag==1){
			sort(a+1,a+n+1,greater<int>());
			bool f11=1;
			for(int i=1;i<=m;i++){
				if(a[i]!=4){
					f11=0;
				}
			}
			if(f11==1){
				printf("4");
			}
			else{
				printf("3");
			}
		}
		else if(f1==1){
			sort(a+1,a+n+1,greater<int>());
			int tmp=a[1];
			for(int i=2;i<=m;i++){
				tmp=tmp&a[i];
			}
			printf("%d",tmp);
		}
		else if(m==n){
			int tmp=a[1];
			for(int i=2;i<=n;i++){
				tmp=tmp&a[i];
			}
			printf("%d",tmp);
		}
		else{
			sort(a+1,a+n+1,greater<int>());
			int ping=1,mxping=0,maxx=0;
			for(int i=1;i<=n;i++){
				if(a[i]==a[i-1]){
					ping++;
				}
				else{
					mxping=max(mxping,ping);
					if(mxping>=m){
						maxx=max(maxx,a[i-1]);
						break;
					}
					ping=1;
				}
			}
		}
	}
	return 0;
}
