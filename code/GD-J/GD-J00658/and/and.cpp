#include<bits/stdc++.h>
using namespace std;
int a[200005],m,n,c1,c2,sum,ans,t1[25],t2[25],t3[25],cnt1,cnt2,maxx=INT_MIN;
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++){
			ans=1;
			sum=0;
			cnt1=0;
			cnt2=0;
			memset(t1,0,sizeof(t1));
			memset(t2,0,sizeof(t2));
			c1=a[i];
			c2=a[j];
			while(c1!=0){
				t1[++cnt1]=c1%2;
				c1/=2;
			}
			while(c2!=0){
				t2[++cnt2]=c2%2;
				c2/=2;
			}
			for(int k=max(cnt1,cnt2);0<k;k--){
				if(t1[k]==0) t3[k]=0;
				else if(t2[k]==1) t3[k]=1;
			}
			for(int k=1;k<=max(cnt1,cnt2);k++){
				sum+=t3[k]*ans;
				ans*=2;
			}
			maxx=max(sum,maxx);
		}
	}
	printf("%d",maxx);

	return 0;
}
