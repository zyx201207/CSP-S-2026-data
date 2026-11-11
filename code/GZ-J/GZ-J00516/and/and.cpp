//GZ-J00516 陈载烁阳 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    if(m==1){
    	printf("%d",a[1]);
    	return 0;
	}
   else  if(m==n){
    	long long k=a[1];
    	for(int i=1;i<n;i++)
    	k=k&a[i];
    	printf("%d",k);
    	return 0;
	}
	else if(m<=6){
		int k=a[1]; 
    for(int i=2;i<m;i++) k=k&a[i];
    for(int i=m;i<n;i++){
    	int k1=k&a[i];
    	ans=max(ans,k1);
	}
    printf("%d",ans);
    return 0;
	}
		printf("%d",a[1]);
    
	
    	
	

	return 0;
} 
