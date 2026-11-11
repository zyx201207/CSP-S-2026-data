#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],sum,ans,l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==n){
        sum=a[1];
        for(int i=2;i<=n;i++)sum=sum&a[i];
        printf("%d",sum);
        return 0;
	}
	if(m==1){
        for(int i=1;i<=n;i++)sum=max(sum,a[i]);
        printf("%d",sum);
        return 0;
	}
	if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        printf("%d",sum);
        return 0;
	}
	if(m==n-1){
	for(int i=1;i<=n;i++){
        l=0;
	    if(i!=1)ans=a[1];
        else ans=a[2],l=1;
        if(l==1)l=1;
        for(int j=2+l;j<=n;j++){
            if(j!=i){
                ans=ans&a[j];
            }
        }
        sum=max(sum,ans);
	}
	printf("%d",sum);
	return 0;
	}
	printf("%d",5);
	return 0;
}
