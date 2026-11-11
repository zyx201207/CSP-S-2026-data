#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num=1;
int a[200005];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cout<<(3&15);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(ans<a[i])ans=a[i];
		}
		printf("%d",ans);
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(ans<(a[i]&a[j]))ans=(a[i]&a[j]);
			}
		}
		printf("%d",ans);
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		printf("%d",ans);
		return 0;
	}else if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		int ans1=ans;
		for(int i=1;i<=n;i++){
			if(ans<(ans1^a[i]))ans=(ans1^a[i]);
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
