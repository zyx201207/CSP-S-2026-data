#include <bits/stdc++.h>
using namespace std;
int m,n,a[10005],ma=0,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);

	if(m==1){
		printf("%d",a[n]);	
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<n;j++){
				ma = max(ma,(a[i]&a[j]));
			}
		}
		printf("%d",ma);	
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans = (ans&a[i]);
		}
		printf("%d",ans);	
	}else{
		cout<<0;
		
	}
	
	
	return 0;
}
