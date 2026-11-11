#include<bits/stdc++.h>
using namespace std;
bool a[200002][36],ok=1;
int n,m,s[200002],c[200002];
void tn(int ii,int x){
	int un=32;
	while(x){
		a[ii][un]=x%2;
		if(a[ii][un]==0)ok=0;
		x/=2;
		un--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	//puts("pop");
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		//s[i]=i;
		tn(i,s[i]);
	}
	if(ok){
		sort(s+1,s+n+1);
		int ans=2147483647;
		for(int i=n;i>n-m;i--){
			ans&=s[i];
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=32;i++){
		//puts("pop");
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(c[j]==1){
				cnt++;
				a[j][33]=1;
				continue;
			}
			if(a[j][i]==0){
				cnt++;
				a[j][33]=1;
			}
		}
		if(cnt+m<=n){
			for(int j=1;j<=n;j++){
				c[j]=a[j][33];
			}
		}
		if(cnt+m==n||i==32){
			int ans=2147483647;
			for(int j=1;j<=n;j++){
				if(c[j]==0){
					ans&=s[j];
				}
			}
			printf("%d",ans);
			return 0;
		}
		for(int j=1;j<=n;j++){
			a[j][33]=0;
		}
	}
	return 0;
}
