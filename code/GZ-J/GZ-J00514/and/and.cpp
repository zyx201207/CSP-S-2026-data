//GZ-J00514 ÑîµÂÓî 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[201011],p1[201011],p2[201011];
int ans1,ans2,ans3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a[1]);
	ans1=a[1];
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		ans1&=a[1];
		ans2=max(ans2,a[i]);
	}
	if(n==m){
		printf("%d\n",ans1);
		return 0;
	}else if(m==1){
		printf("%d\n",ans2);
		return 0;
	}else if(ans2<4){
		printf("0\n");
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans3=max(ans3,a[i]&a[j]);
			}
		}
		printf("%d\n",ans3);
	}else if(m==n-1){
		p2[n]=a[n];
		for(int i=n-1;i>=1;i--) p2[i]=p2[i+1]&a[i];
		for(int i=2;i<n;i++) p1[i]=p1[i-1]&a[i],ans3=max(ans3,p1[i-1]&p2[i+1]);
		printf("%d\n",max(ans3,max(p1[n-1],p2[2])));
	}else{
		sort(a+1,a+n+1);
		printf("%d\n",a[n-m+1]);
	}
	return 0;
}
