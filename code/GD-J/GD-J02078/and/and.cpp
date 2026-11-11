#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
int n,m,a[N];
int s[N][60];
int ans[N],l1=0;
bool is[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++)
		is[i]=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ma=0;
	for(int i=1;i<=n;i++){
		int x=a[i],l=0;
		while(x!=0){
			s[i][++l]=x%2;
			x/=2;
		}
		ma=max(ma,l);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=ma;j++)
//			printf("%d",s[i][j]);
//		puts("");
//	}
	for(int j=ma;j>=1;j--){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!is[i])
				continue;
			tot+=s[i][j];
		}
//		printf("^%d",tot);
		if(tot<m){
			continue;
		}
		for(int i=1;i<=n;i++){
			if(!is[i])
			continue;
			if(s[i][j]==0)
				is[i]=0;
		}
		ans[++l1]=j;
	}
	int res=0;
//	printf("%d",l1);
	for(int i=1;i<=l1;i++){
		res+=pow(2,ans[i]-1);
	}
	printf("%d",res);
	return 0;
}
